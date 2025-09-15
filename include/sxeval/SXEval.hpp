#ifndef SXEVAL_SXEVAL_HPP
#define SXEVAL_SXEVAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/AOperand.hpp"
#include "sxeval/operations/OperationsFactory.hpp"
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
#include <sstream>


/* DEFINITIONS */

namespace sxeval {

template <typename T>
using resolveVariable_t = std::function<T&(const std::string&)>;
template <typename T>
using resolveEncapsulated_t = std::function<
    std::function<T(void)>(const std::string&)>;

/**
 * @brief The SXEval class is used to evaluate s-expressions.
 *
 * It allows user-custom operatinos as well as user-owned variables and
 * encapsulated variables.
 *
 * It can build an expression tree from a s-expression and evaluate it.
 * It can also compute the result of an expression without building its tree, 
 * which is much slower than the evaluation but faster than building the tree.
 * This latter method is useful for quick/unique evaluations without the
 * overhead of building a tree while the former is useful for repeated
 * evaluations of the same expression.
 *
 * @tparam T The type of the values handle by the s-expression. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class SXEval {
public:
    /**
     * @brief Default constructor.
     */
    inline SXEval() {}

    /**
     * @brief Register an operation.
     *
     * @tparam OP The operation to register. The operation must inherit from
     * sxeval::AOperation<T>.
     */
    template <typename OP>
    inline void registerOperation() { _operationsFactory.template add<OP>(); }

    /**
     * @brief Build the expression tree from a s-expression.
     *
     * @param expression The expression to parse.
     * @param resolveVariable A function to resolve variable names to their
     * values. The function should take a string as input and return a reference
     * to the variable's value. If the variable is not found, an exception
     * should be thrown.
     * @param resolveEncapsulated A function to resolve encapsulated variable
     * names to their getter functions. The function should take a string as
     * input and return a function that returns the variable's value when
     * called. If the encapsulated variable is not found, an exception should be
     * thrown.
     * @throws std::runtime_error if a variable cannot be resolved or if the
     * expression is invalid.
     */
    void build(const std::string& expression,
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>(),
        const resolveEncapsulated_t<T>& resolveEncapsulated
        = resolveEncapsulated_t<T>());

    /**
     * @brief Build the expression tree from a s-expression.
     *
     * @param expression The expression to parse.
     * @param resolveEncapsulated A function to resolve encapsulated variable
     * names to their getter functions. The function should take a string as
     * input and return a function that returns the variable's value when
     * called. If the encapsulated variable is not found, an exception should be
     * thrown.
     * @param resolveVariable A function to resolve variable names to their
     * values. The function should take a string as input and return a reference
     * to the variable's value. If the variable is not found, an exception
     * should be thrown.
     * @throws std::runtime_error if a variable cannot be resolved or if the
     * expression is invalid.
     * @note This is an overload of the build() method that allows
     * specifying the resolveEncapsulated function first, which can be useful
     * if the resolveVariable function is not needed.
     */
    inline void build(const std::string& expression,
        const resolveEncapsulated_t<T>& resolveEncapsulated
        = resolveEncapsulated_t<T>(),
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>())
    { build(expression, resolveVariable, resolveEncapsulated); }

    /**
     * @brief Compute the result of the expression tree.
     *
     * @return The result of the computation.
     * @throws std::runtime_error if no operations have been registered or if
     * the evaluation fails.
     * @note build() must have been called before calling this method.
     */
    T execute() const;

    /**
     * @brief Compute the result of an expression without building its tree.
     *
     * @param expression The expression to compute.
     * @param resolveVariable A function to resolve variable names to their
     * values. The function should take a string as input and return a reference
     * to the variable's value. If the variable is not found, an exception
     * should be thrown.
     * @param resolveEncapsulated A function to resolve encapsulated variable
     * names to their getter functions. The function should take a string as
     * input and return a function that returns the variable's value when
     * called. If the encapsulated variable is not found, an exception should be
     * thrown.
     * @return The result of the computation.
     * @throws std::runtime_error if a variable cannot be resolved or if the
     * expression is invalid.
     * @note This method does not build the expression tree, it only computes
     * the result of the expression. It is useful for quick/unique evaluations
     * without the overhead of building a tree.
     */
    T interpret(const std::string& expression,
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>(),
        const resolveEncapsulated_t<T>& resolveEncapsulated
        = resolveEncapsulated_t<T>()) const;

    /**
     * @brief Compute the result of an expression without building its tree.
     *
     * @param expression The expression to compute.
     * @param resolveEncapsulated A function to resolve encapsulated variable
     * names to their getter functions. The function should take a string as
     * input and return a function that returns the variable's value when
     * called. If the encapsulated variable is not found, an exception should be
     * thrown.
     * @param resolveVariable A function to resolve variable names to their
     * values. The function should take a string as input and return a reference
     * to the variable's value. If the variable is not found, an exception
     * should be thrown.
     * @return The result of the computation.
     * @throws std::runtime_error if a variable cannot be resolved or if the
     * expression is invalid.
     * @note This method does not build the expression tree, it only computes
     * the result of the expression. It is useful for quick/unique evaluations
     * without the overhead of building a tree.
     * @note This is an overload of the interpret() method that allows
     * specifying the resolveEncapsulated function first, which can be useful if
     * the resolveVariable function is not needed.
     */
    inline T interpret(const std::string& expression,
        const resolveEncapsulated_t<T>& resolveEncapsulated
        = resolveEncapsulated_t<T>(),
        const resolveVariable_t<T>& resolveVariable = resolveVariable_t<T>())
        const
    { return interpret(expression, resolveVariable, resolveEncapsulated); }

    /**
     * @brief Convert the expression tree to a string representation.
     *
     * @return A string representation of the expression tree.
     */
    std::string toString() const;

private:
    struct _Node {
        std::unique_ptr<AInstruction<T>> instruct;
        _Node* parent;
        std::vector<_Node> subnodes;

        #ifdef SXEVAL_DEBUG
        int id = -1;
        #endif /* SXEVAL_DEBUG */
    };

    static void _skipChars(const std::string& s, size_t* idx);
    static std::string _getNextSymbol(const std::string& s, size_t* idx);
    _Node _build(size_t* idx, const resolveVariable_t<T>& resolveVariable,
        const resolveEncapsulated_t<T>& resolveEncapsulated);
    static void _fillParents(_Node& parent);
    static void _buildTreeStr(std::ostream& oss, const _Node& node, size_t depth
        );
    T _interpret(const std::string& exp, size_t* idx,
        const resolveVariable_t<T>& resolveVariable,
        const resolveEncapsulated_t<T>& resolveEncapsulated) const;

    #ifdef SXEVAL_DEBUG
    int nodeCount = 0;
    #endif /* SXEVAL_DEBUG */

    operations::OperationsFactory<T> _operationsFactory;
    std::vector<AOperation<T>*> _operations;
    std::vector<EncapsulatedVariable<T>*> _encapsulated;
    _Node _lastOperation;
    std::string _expression;

};

/**
 * @brief Output stream operator for SXEval.
 * @param os The output stream.
 * @param obj The SXEval object to output.
 * @return The output stream.
 * @note This operator outputs the string representation of the expression tree
 * of the SXEval object.
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const SXEval<T>& obj) {
    return os << obj.toString();
}

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::SXEval<T>::build(const std::string& expression,
    const resolveVariable_t<T>& resolveVariable,
    const resolveEncapsulated_t<T>& resolveEncapsulated)
{
    _operations.clear();
    _encapsulated.clear();
    _expression = expression;
    size_t idx = 0;
    _lastOperation = _build(&idx, resolveVariable, resolveEncapsulated);
    _fillParents(_lastOperation);
}

template <typename T>
T sxeval::SXEval<T>::execute() const {
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
T sxeval::SXEval<T>::interpret(const std::string& expression,
    const resolveVariable_t<T>& resolveVariable,
    const resolveEncapsulated_t<T>& resolveEncapsulated) const
{
    size_t idx = 0;
    return _interpret(expression, &idx, resolveVariable, resolveEncapsulated);
}

template <typename T>
T sxeval::SXEval<T>::_interpret(const std::string& exp, size_t* idx,
    const resolveVariable_t<T>& resolveVariable,
    const resolveEncapsulated_t<T>& resolveEncapsulated) const
{
    _skipChars(exp, idx);

    if (exp[*idx] == '(') {
        /* ### OPERATION ### */
        (*idx)++;
        const auto symbol = _getNextSymbol(exp, idx);
        std::vector<std::unique_ptr<AInstruction<T>>> args;
        std::vector<AInstruction<T>*> pargs;
        _skipChars(exp, idx);
        while (exp[*idx] != ')') {
            const auto val = _interpret(exp, idx, resolveVariable,
                resolveEncapsulated);
            args.push_back(std::unique_ptr<AInstruction<T>>(new Value<T>(val)));
            pargs.push_back(args.back().get());
            _skipChars(exp, idx);
        }
        (*idx)++;
        return _operationsFactory.compute(symbol, pargs);

    } else {
        /* ### OPERANDS ### */
        const auto symbol = _getNextSymbol(exp, idx);
        T res;
        try {
            res = StringToType<T>(symbol);
        } catch (...) {
            /* as this is not castable, this may be a variable */
            try {
                res = resolveVariable(symbol);
            } catch (...) {
                /* as it has not been found, this is likely an
                 * encapsulated variable */
                try {
                    const auto get = resolveEncapsulated(symbol);
                    res = get();
                } catch (...) {
                    /* last chance, check if it is a true/false keyword
                     */
                    if (symbol == "true") {
                        res = 1;
                    } else if (symbol == "false") {
                        res = 0;
                    } else {
                        throw std::runtime_error("Unknown variable: " + symbol);
                    }
                }
            }
        }
        return res;
    }
}

template <typename T>
std::string sxeval::SXEval<T>::toString() const {
    std::ostringstream oss;
    _buildTreeStr(oss, _lastOperation, 0);
    return oss.str();
}

template <typename T>
void sxeval::SXEval<T>::_skipChars(const std::string& s, size_t* i) {
    while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n'  || s[*i] == '\r' )
    {
        (*i)++;
    }
}

template <typename T>
std::string sxeval::SXEval<T>::_getNextSymbol(const std::string& s, size_t* i) {
    _skipChars(s, i);
    std::string symbol;
    char c = s[*i];
    while (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '('
        && c != ')')
    {
        symbol += c;
        (*i)++;
        c = s[*i];
    }
    return symbol;
}

template <typename T>
typename sxeval::SXEval<T>::_Node sxeval::SXEval<T>::_build(size_t* idx,
    const resolveVariable_t<T>& resolveVariable,
    const resolveEncapsulated_t<T>& resolveEncapsulated)
{
    #ifdef SXEVAL_DEBUG
    {
        std::ostringstream oss;
        oss << "[DEBUG] " << __FILE__ << ":" << __LINE__
            << " in " << __func__ << "(): " << "parsing '"
            << _expression << "'\n";
        std::cerr << oss.str();
    }
    #endif /* SXEVAL_DEBUG */
    _skipChars(_expression, idx);

    if (_expression[*idx] == '(') {
        /* ### OPERATION ### */
        (*idx)++;
        const auto symbol = _getNextSymbol(_expression, idx);
        _Node node;
        node.parent = nullptr;
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
        _skipChars(_expression, idx);
        while (_expression[*idx] != ')') {
            node.subnodes.push_back(_build(idx, resolveVariable,
                resolveEncapsulated));
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
            _skipChars(_expression, idx);
        }
        (*idx)++;
        std::vector<AInstruction<T>*> args;
        for (auto& subnode : node.subnodes) {
            args.push_back(subnode.instruct.get());
        }
        node.instruct = _operationsFactory.create(symbol, args);
        _operations.push_back(
            dynamic_cast<AOperation<T>*>(node.instruct.get()));
        return std::move(node);

    } else {
        /* ### OPERANDS ### */
        const auto symbol = _getNextSymbol(_expression, idx);
        _Node node;
        try {
            T val = StringToType<T>(symbol);
            node = { std::unique_ptr<AInstruction<T>>(new Value<T>(val)),
                nullptr, {} };
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
                node = {
                    std::unique_ptr<AInstruction<T>>(
                        new Variable<T>(var, symbol)
                    ), nullptr, {} };
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
                    auto get = resolveEncapsulated(symbol);
                    node = {
                        std::unique_ptr<AInstruction<T>>(
                            new EncapsulatedVariable<T>(get, symbol)
                        ), nullptr, {} };
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
                    if (symbol == "true") {
                        node = {
                            std::unique_ptr<AInstruction<T>>(new Value<T>(1)),
                            nullptr, {} };
                    } else if (symbol == "false") {
                        node = {
                            std::unique_ptr<AInstruction<T>>(new Value<T>(0)),
                            nullptr, {} };
                    } else {
                        throw std::runtime_error("Unknown variable: " + symbol);
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
        return node;
    }
}

template <typename T>
void sxeval::SXEval<T>::_fillParents(_Node& parent) {
    for (auto& child : parent.subnodes) {
        child.parent = &parent;
        _fillParents(child);
    }
}

template <typename T>
void sxeval::SXEval<T>::_buildTreeStr(std::ostream& oss, const _Node& node,
    size_t depth)
{
    if (depth > 0) {
        for (size_t i = 0; i < depth - 1; ++i) {
            const _Node* parent = &node;
            const _Node* child = nullptr;
            for (size_t j = 0; j < depth - i; ++j) {
                child = parent;
                parent = parent->parent;
            }
            if (!(parent != nullptr && parent->subnodes.back().instruct.get()
                == child->instruct.get()))
            {
                oss << "│  ";
            } else {
                oss << "   ";
            }
        }
        if (node.parent != nullptr &&
            node.parent->subnodes.back().instruct.get() != node.instruct.get())
        {
            oss << "├─ ";
        } else {
            oss << "└─ ";
        }
    }
    oss << node.instruct->toString() << std::endl;
    for (const auto& child : node.subnodes) {
        _buildTreeStr(oss, child, depth + 1);
    }
}

#endif /* SXEVAL_SXEVAL_HPP */
