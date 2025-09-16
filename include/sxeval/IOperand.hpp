#ifndef SXEVAL_IOPERAND_HPP
#define SXEVAL_IOPERAND_HPP

#include "sxeval/IInstruction.hpp"

namespace sxeval {

/**
 * @brief The IOperand class is an interface for operands.
 *
 * @tparam T The type of values handled by the SXEval library. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class IOperand : public virtual IInstruction<T> {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~IOperand() override = default;

};

} /* namespace sxeval */
#endif /* SXEVAL_IOPERAND_HPP */
