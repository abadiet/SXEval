#ifndef SXEVAL_SXEVAL_HPP
#define SXEVAL_SXEVAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/AOperand.hpp"
#include "sxeval/operations/Operations.hpp"
#include "sxeval/Value.hpp"
#include "sxeval/Variable.hpp"
#include "sxeval/EncapsulatedVariable.hpp"
#include "sxeval/utils.hpp"
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
    inline SXEval() {}
    inline SXEval(char* exp,
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>(),
        const resolveEncapsulated_t<T> resolveEncapsulated
        = resolveEncapsulated_t<T>()) :
        _resolveEncapsulated(resolveEncapsulated),
        _lastOperation(_build(&exp, resolveVariable)) {}
    inline SXEval(char* exp,
        const resolveEncapsulated_t<T> resolveEncapsulated
        = resolveEncapsulated_t<T>(),
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>()) :
        _resolveEncapsulated(resolveEncapsulated),
        _lastOperation(_build(&exp, resolveVariable)) {}

    T evaluate() const;

private:
    struct _Node {
        std::unique_ptr<AInstruction<T>> instruct;
        std::vector<_Node> subnodes;

        #ifdef SXEVAL_DEBUG
        int id = -1;
        #endif /* SXEVAL_DEBUG */
    };

    void _skipChars(char **exp) const;
    char* _getNextSymbol(char **exp) const;
    _Node _build(char **exp, const resolveVariable_t<T>& resolveVariable);

    #ifdef SXEVAL_DEBUG
    int nodeCount = 0;
    #endif /* SXEVAL_DEBUG */

    std::vector<AOperation<T>*> _operations;
    std::vector<EncapsulatedVariable<T>*> _encapsulated;
    const resolveEncapsulated_t<T> _resolveEncapsulated;
    _Node _lastOperation;

};

} /* namespace sxeval */


/* IMPLEMENTATIONS */

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
void sxeval::SXEval<T>::_skipChars(char **exp) const {
    while (**exp == ' ' || **exp == '\t' || **exp == '\n' || **exp == '\r') {
        (*exp)++;
    }
}

template <typename T>
char* sxeval::SXEval<T>::_getNextSymbol(char **exp) const {
    _skipChars(exp);
    size_t len = 0;
    while ((*exp)[len] != ' ' && (*exp)[len] != '\t' && (*exp)[len] != '\n'
        && (*exp)[len] != '\r' && (*exp)[len] != '(' && (*exp)[len] != ')')
    {
        len++;
    }
    char *symbol = new char[len + 1];
    std::strncpy(symbol, *exp, len);
    symbol[len] = '\0';
    *exp += len;
    return symbol;
}

template <typename T>
typename sxeval::SXEval<T>::_Node sxeval::SXEval<T>::_build(char **exp,
    const resolveVariable_t<T>& resolveVariable)
{
    #ifdef SXEVAL_DEBUG
    {
        std::ostringstream oss;
        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
            << " in " << __func__ << "(): " << "parsing '"
            << *exp << "'\n";
        std::cerr << oss.str();
    }
    #endif /* SXEVAL_DEBUG */
    _skipChars(exp);

    if (**exp == '(') {
        (*exp)++;
        const char* symbol = _getNextSymbol(exp);
        _Node node;
        #ifdef SXEVAL_DEBUG
        {
            node.id = nodeCount++;
            std::ostringstream oss;
            oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                << " in " << __func__ << "(): node " << node.id
                << ": found operation " << symbol << "\n";
            std::cerr << oss.str();
        }
        #endif /* SXEVAL_DEBUG */
        _skipChars(exp);
        while (**exp != ')') {
            node.subnodes.push_back(_build(exp, resolveVariable));
            #ifdef SXEVAL_DEBUG
            {
                std::ostringstream oss;
                oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                    << " in " << __func__ << "(): -> node "
                    << node.subnodes.back().id << " added to node " << node.id
                    << "\n";
                std::cerr << oss.str();
            }
            #endif /* SXEVAL_DEBUG */
            _skipChars(exp);
        }
        (*exp)++;
        std::vector<AInstruction<T>*> args;
        for (auto& subnode : node.subnodes) {
            args.push_back(subnode.instruct.get());
        }
        node.instruct = sxeval::operations::Operations<T>::create(symbol, args);
        _operations.push_back(
            dynamic_cast<AOperation<T>*>(node.instruct.get()));
        delete[] symbol;
        return node;
    } else {
        const char* symbol = _getNextSymbol(exp);
        _Node node;
        try {
            T val = StringToType<T>(symbol);
            node = {std::make_unique<Value<T>>(val), {}};
            #ifdef SXEVAL_DEBUG
            {
                node.id = nodeCount++;
                std::ostringstream oss;
                oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                    << " in " << __func__ << "(): node " << node.id
                    << ": found value " << symbol << " (="
                    << node.instruct->getResult() << ")\n";
                std::cerr << oss.str();
            }
            #endif /* SXEVAL_DEBUG */
        } catch (...) {
            /* as this is not castable, this may be a variable */
            try {
                T& var = resolveVariable(symbol);
                node = {std::make_unique<Variable<T>>(var), {}};
                #ifdef SXEVAL_DEBUG
                {
                    node.id = nodeCount++;
                    std::ostringstream oss;
                    oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                        << " in " << __func__ << "(): node " << node.id
                        << ": found variable " << symbol << " (="
                        << node.instruct->getResult() << ")\n";
                    std::cerr << oss.str();
                }
                #endif /* SXEVAL_DEBUG */
            } catch (...) {
                /* as it has not been found, this is likely an
                 * encapsulated variable */
                try {
                    auto get = _resolveEncapsulated(symbol);
                    node = {std::make_unique<EncapsulatedVariable<T>>(get), {}};
                    _encapsulated.push_back(
                        dynamic_cast<EncapsulatedVariable<T>*>(
                        node.instruct.get()));
                    #ifdef SXEVAL_DEBUG
                    {
                        node.id = nodeCount++;
                        std::ostringstream oss;
                        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                            << " in " << __func__ << "(): node " << node.id
                            << ": found encapsulated variable " << symbol
                            << " (=" << node.instruct->getResult() << ")\n";
                        std::cerr << oss.str();
                    }
                    #endif /* SXEVAL_DEBUG */
                } catch (...) {
                    /* last chance, check if it is a true/false keyword
                     */
                    if (std::strcmp(symbol, "true") == 0) {
                        node = {std::make_unique<Value<T>>(1), {}};
                    } else if (std::strcmp(symbol, "false") == 0) {
                        node = {std::make_unique<Value<T>>(0), {}};
                    } else {
                        throw std::runtime_error("Unknown variable: " +
                            std::string(symbol));
                    }
                    #ifdef SXEVAL_DEBUG
                    {
                        node.id = nodeCount++;
                        std::ostringstream oss;
                        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
                            << " in " << __func__ << "(): node " << node.id
                            << ": found boolean value " << symbol
                            << " (=" << node.instruct->getResult() << ")\n";
                        std::cerr << oss.str();
                    }
                    #endif /* SXEVAL_DEBUG */
                }
            }
        }
        delete[] symbol;
        return node;
    }
}

#endif /* SXEVAL_SXEVAL_HPP */
