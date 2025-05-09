#ifndef SXEVAL_VALUE_HPP
#define SXEVAL_VALUE_HPP

#include "sxeval/AOperand.hpp"
#include <string>


/* DEFINITIONS */

namespace sxeval {

template <typename T>
class Value : public AOperand<T> {
public:
    inline Value(T val) : AOperand<T>(_val), _val(val) {}

    inline std::string toString() const override {
        return std::to_string(_val); }

private:
    T _val;

};

} /* namespace sxeval */
#endif /* SXEVAL_VALUE_HPP */
