#ifndef SXEVAL_VARIABLE_HPP
#define SXEVAL_VARIABLE_HPP

#include "sxeval/IOperand.hpp"

namespace sxeval {

/**
 * @brief The Variable class represents a variable in the SXEval library.
 *
 * @tparam T The type of the variable. The supported types are int, signed char,
 * short int, long int, unsigned int, unsigned char, unsigned long int, float,
 * double and long double.
 */
template <typename T>
class Variable : public virtual IOperand<T> {
public:
    /**
     * @brief Default constructor.
     *
     * @param var The variable to store.
     * @param name The name of the variable.
     * @note The name is used for debugging and string representation purposes.
     */
    inline Variable(T& var, const std::string& name) : _var(var), _name(name) {}

    /**
     * @brief Get a reference to the variable.
     *
     * @return A reference to the variable.
     */
    inline T& getResult() override { return _var; }

    /**
     * @brief String representation of the variable.
     *
     * @return The name of the variable.
     */
    inline std::string toString() const override { return _name; }

private:
    T& _var;
    const std::string _name;

};

} /* namespace sxeval */
#endif /* SXEVAL_VARIABLE_HPP */
