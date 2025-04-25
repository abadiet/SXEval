#ifndef SXEVAL_VALUE_HPP
#define SXEVAL_VALUE_HPP

#include "sxeval/AOperand.hpp"

namespace sxeval {

template <typename T>
class Value : public AOperand<T> {
public:
    inline Value(T val) : AOperand<T>(_val), _val(val) {}

private:
    T _val;

};

} /* namespace sxeval */
#endif /* SXEVAL_VALUE_HPP */
