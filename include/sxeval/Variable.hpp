#ifndef SXEVAL_VARIABLE_HPP
#define SXEVAL_VARIABLE_HPP

#include "sxeval/AOperand.hpp"

namespace sxeval {

template <typename T>
class Variable : public AOperand<T> {
public:
    inline Variable(T& var) : AOperand<T>(var) {}

};

} /* namespace sxeval */


#endif /* SXEVAL_VARIABLE_HPP */
