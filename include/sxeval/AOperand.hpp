#ifndef SXEVAL_IOPERAND_HPP
#define SXEVAL_IOPERAND_HPP

#include "sxeval/AInstruction.hpp"

namespace sxeval {

template <typename T>
class AOperand : public AInstruction<T> {
public:
    inline AOperand(T& result) : AInstruction<T>(result) {}

};

} /* namespace sxeval */
#endif /* SXEVAL_IOPERAND_HPP */
