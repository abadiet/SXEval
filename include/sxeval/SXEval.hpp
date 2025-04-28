#ifndef SXEVAL_SXEVAL_HPP
#define SXEVAL_SXEVAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/AOperand.hpp"
#include "sxeval/operations/Operations.hpp"
#include "sxeval/Value.hpp"
#include "sxeval/Variable.hpp"
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
using operations_t = std::vector<std::unique_ptr<AOperation<T>>>;
template <typename T>
using operands_t = std::vector<std::unique_ptr<AOperand<T>>>;

template <typename T>
class SXEval {
public:
    SXEval(sexp_t sexp, const resolveVariable_t<T>& resolveVariable);
    SXEval(char* exp, const resolveVariable_t<T>& resolveVariable);

    T evaluate() const;

private:
    void _build(operations_t<T>& operations,  operands_t<T>& operands,
        sexp_t *exp, std::vector<AInstruction<T>*>& args,
        const resolveVariable_t<T>& resolveVariable);

    operations_t<T> _operations;
    operands_t<T> _operands;

};

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
sxeval::SXEval<T>::SXEval(sexp_t sexp,
    const resolveVariable_t<T>& resolveVariable)
{
    std::vector<AInstruction<T>*> dummyargs;
    _build(_operations, _operands, sexp, dummyargs, resolveVariable);
}

template <typename T>
sxeval::SXEval<T>::SXEval(char* exp,
    const resolveVariable_t<T>& resolveVariable)
{
    sexp_t *sexp = parse_sexp(exp, std::strlen(exp));
    std::vector<AInstruction<T>*> dummyargs;
    _build(_operations, _operands, sexp, dummyargs, resolveVariable);
    destroy_sexp(sexp);
    sexp_cleanup();
}

template <typename T>
T sxeval::SXEval<T>::evaluate() const {
    for (const auto& op : _operations) {
        op->execute();
    }
    return _operations.back()->getResult();
}

template <typename T>
void sxeval::SXEval<T>::_build(operations_t<T>& operations,
    operands_t<T>& operands, sexp_t *exp, std::vector<AInstruction<T>*>& args,
    const resolveVariable_t<T>& resolveVariable)
{
    switch (exp->ty) {
        case SEXP_VALUE:
            if (exp->aty != SEXP_BINARY) {
                try {
                    T val = stringToType<T>(exp->val);
                    operands.push_back(std::make_unique<sxeval::Value<T>>(val));
                    #ifdef SXEVAL_DEBUG
                    {
                        std::ostringstream oss;
                        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                            << " in " << __func__ << "(): operation"
                            << operations.size() << "    found value "
                            << operands.back()->getResult() << "\n";
                            std::cerr << oss.str();
                    }
                    #endif /* SXEVAL_DEBUG */
                } catch (...) {
                    /* as this is not castable, this is likely a variable */
                    T& var = resolveVariable(exp->val);
                    operands.push_back(std::make_unique<sxeval::Variable<T>>(
                        var));
                    #ifdef SXEVAL_DEBUG
                    {
                        std::ostringstream oss;
                        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                            << " in " << __func__ << "(): operation"
                            << operations.size() << "    found variable "
                            << exp->val << " (=" << operands.back()->getResult()
                            << ")\n";
                            std::cerr << oss.str();
                    }
                    #endif /* SXEVAL_DEBUG */
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
                    << operations.size() << "    found operation "
                    << exp->list->val << "\n";
                    std::cerr << oss.str();
            }
            #endif /* SXEVAL_DEBUG */

            {
                std::vector<sxeval::AInstruction<T>*> opargs;

                {
                    sexp_t *elem = exp->list->next;
                    while (elem) {
                        _build(operations, operands, elem, opargs,
                            resolveVariable);
                        #ifdef SXEVAL_DEBUG
                        {
                            std::ostringstream oss;
                            oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                                << " in " << __func__ << "(): operation"
                                << operations.size() << "        arg "
                                << opargs.size() << " (="
                                << opargs.back()->getResult() << ")\n";
                                std::cerr << oss.str();
                        }
                        #endif /* SXEVAL_DEBUG */
                        elem = elem->next;
                    }
                }

                operations.push_back(sxeval::operations::Operations<T>::create(
                    exp->list->val, opargs));
                args.push_back(operations.back().get());
                #ifdef SXEVAL_DEBUG
                    operations.back()->execute();
                #endif /* SXEVAL_DEBUG */
            }
            break;
    }
}

#endif /* SXEVAL_SXEVAL_HPP */
