#ifndef SXEVAL_ENCASPULATED_VARIABLE_HPP
#define SXEVAL_ENCASPULATED_VARIABLE_HPP

#include "sxeval/AOperand.hpp"
#include <functional>

namespace sxeval {

/**
 * @brief The EncapsulatedVariable class represents a variable that can be
 * encapsulated in an unaccessible Object.
 *
 * @tparam T The type of the variable. The supported types are int, signed char,
 * short int, long int, unsigned int, unsigned char, unsigned long int, float,
 * double and long double.
 */
template <typename T>
class EncapsulatedVariable : public AOperand<T> {
public:
    /**
     * @brief Default constructor.
     *
     * @param get The function to retrieve the value of the variable.
     * @param name The name of the variable.
     * @note The name is used for debugging and string representation purposes.
     */
    inline EncapsulatedVariable(const std::function<T(void)> get,
        const std::string& name) :
        AOperand<T>(_var), _get(get), _name(name) {}

    /**
     * @brief Retrieve the value of the encapsulated variable.
     */
    inline void retrieve() { _var = _get(); }

    /**
     * @brief String representation of the encapsulated variable.
     *
     * @return The name of the encapsulated variable.
     */
    inline std::string toString() const override { return _name; }

private:
    T _var;
    const std::function<T(void)> _get;
    const std::string _name;

};

} /* namespace sxeval */
#endif /* SXEVAL_ENCASPULATED_VARIABLE_HPP */
