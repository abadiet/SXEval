#ifndef SXEVAL_VALUE_HPP
#define SXEVAL_VALUE_HPP

#include "sxeval/AOperand.hpp"
#include <string>


/* DEFINITIONS */

namespace sxeval {

/**
 * @brief The Value class represents a constant value in the SXEval library.
 *
 * @tparam T The type of the value. The supported types are int, signed char,
 * short int, long int, unsigned int, unsigned char, unsigned long int, float,
 * double and long double.
 */
template <typename T>
class Value : public AOperand<T> {
public:
    /**
     * @brief Default constructor.
     *
     * @param val The value to store.
     */
    inline Value(T val) : AOperand<T>(_val), _val(val) {}

    inline std::string toString() const override {
        return std::to_string(_val); }

private:
    T _val;

};

} /* namespace sxeval */
#endif /* SXEVAL_VALUE_HPP */
