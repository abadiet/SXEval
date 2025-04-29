#ifndef SXEVAL_SXEVAL_HPP
#define SXEVAL_SXEVAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/AOperand.hpp"
#include "sxeval/operations/Operations.hpp"
#include "sxeval/Value.hpp"
#include "sxeval/Variable.hpp"
#include "sxeval/EncapsulatedVariable.hpp"
#include "sxeval/utils.hpp"
#include "sexp.h"
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <iostream>
#include <cstring>

#ifdef SXEVAL_DEBUG
#include <sstream>
#endif /* SXEVAL_DEBUG */


/* DEFINITIONS */

namespace sxeval {

template <typename T>
using resolveVariable_t = std::function<T&(const char*)>;
template <typename T>
using resolveEncapsulated_t = std::function<
    std::function<T(void)>(const char*)>;

template <typename T>
class SXEval {
public:
    SXEval() {}
    SXEval(char* exp,
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>(),
        const resolveEncapsulated_t<T> resolveEncapsulated
        = resolveEncapsulated_t<T>());

    T evaluate() const;

private:
    void _build(sexp_t *exp, std::vector<AInstruction<T>*>& args,
        const resolveVariable_t<T>& resolveVariable);

    std::vector<std::unique_ptr<AOperation<T>>> _operations;
    std::vector<std::unique_ptr<AOperand<T>>> _operands;
    std::vector<EncapsulatedVariable<T>*> _encapsulated;
    const resolveEncapsulated_t<T> _resolveEncapsulated;

};

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
sxeval::SXEval<T>::SXEval(char* exp,
    const resolveVariable_t<T>& resolveVariable,
    const resolveEncapsulated_t<T> resolveEncapsulated) :
    _resolveEncapsulated(resolveEncapsulated)
{
    sexp_t *sexp = parse_sexp(exp, std::strlen(exp));
    std::vector<AInstruction<T>*> dummyargs;
    _build(sexp, dummyargs, resolveVariable);
    destroy_sexp(sexp);
    sexp_cleanup();
}

template <typename T>
T sxeval::SXEval<T>::evaluate() const {
    if (_operations.size() == 0) {
        throw std::runtime_error("No operations found");
    }
    for (const auto& op : _encapsulated) {
        op->retrieve();
    }
    for (const auto& op : _operations) {
        op->execute();
    }
    return _operations.back()->getResult();
}

template <typename T>
void sxeval::SXEval<T>::_build(sexp_t *exp, std::vector<AInstruction<T>*>& args,
    const resolveVariable_t<T>& resolveVariable)
{
    switch (exp->ty) {
        case SEXP_VALUE:
            if (exp->aty != SEXP_BINARY) {
                try {
                    T val = stringToType<T>(exp->val);
                    _operands.push_back(std::make_unique<sxeval::Value<T>>(val));
                    #ifdef SXEVAL_DEBUG
                    {
                        std::ostringstream oss;
                        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                            << " in " << __func__ << "(): operation"
                            << _operations.size() << "    found value "
                            << _operands.back()->getResult() << "\n";
                            std::cerr << oss.str();
                    }
                    #endif /* SXEVAL_DEBUG */
                } catch (...) {
                    /* as this is not castable, this may be a variable */
                    try {
                        T& var = resolveVariable(exp->val);
                        _operands.push_back(std::make_unique<
                            sxeval::Variable<T>>(var));
                        #ifdef SXEVAL_DEBUG
                        {
                            std::ostringstream oss;
                            oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                                << " in " << __func__ << "(): operation"
                                << _operations.size() << "    found variable "
                                << exp->val << " (="
                                << _operands.back()->getResult() << ")\n";
                                std::cerr << oss.str();
                        }
                        #endif /* SXEVAL_DEBUG */
                    } catch (...) {
                        /* as it has not been found, this is likely an
                         * encapsulated variable */
                        try {
                            auto get = _resolveEncapsulated(exp->val);
                            _operands.push_back(
                                std::make_unique<EncapsulatedVariable<T>>(get));
                            _encapsulated.push_back(
                                dynamic_cast<EncapsulatedVariable<T>*>(
                                _operands.back().get()));
                            #ifdef SXEVAL_DEBUG
                            {
                                std::ostringstream oss;
                                oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                                    << " in " << __func__ << "(): operation"
                                    << _operations.size()
                                    << "    found encapsulated variable "
                                    << exp->val << "\n";
                                    std::cerr << oss.str();
                            }
                            #endif /* SXEVAL_DEBUG */
                        } catch (...) {
                            throw std::runtime_error("Unknown variable: " +
                                std::string(exp->val));
                        }
                    }
                    /* TODO might be better to not duplicate variables */
                }
                args.push_back(_operands.back().get());
            } else {
                throw std::runtime_error("Binary data not supported");
            }
            break;

        case SEXP_LIST:

            #ifdef SXEVAL_DEBUG
            {
                std::ostringstream oss;
                oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                    << " in " << __func__ << "(): operation"
                    << _operations.size() << "    found operation "
                    << exp->list->val << "\n";
                    std::cerr << oss.str();
            }
            #endif /* SXEVAL_DEBUG */

            {
                std::vector<sxeval::AInstruction<T>*> opargs;

                {
                    sexp_t *elem = exp->list->next;
                    while (elem) {
                        _build(elem, opargs, resolveVariable);
                        #ifdef SXEVAL_DEBUG
                        {
                            std::ostringstream oss;
                            oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                                << " in " << __func__ << "(): operation"
                                << _operations.size() << "        arg "
                                << opargs.size() << " (="
                                << opargs.back()->getResult() << ")\n";
                                std::cerr << oss.str();
                        }
                        #endif /* SXEVAL_DEBUG */
                        elem = elem->next;
                    }
                }

                _operations.push_back(sxeval::operations::Operations<T>::create(
                    exp->list->val, opargs));
                args.push_back(_operations.back().get());
                #ifdef SXEVAL_DEBUG
                    _operations.back()->execute();
                #endif /* SXEVAL_DEBUG */
            }
            break;
    }
}

#endif /* SXEVAL_SXEVAL_HPP */
