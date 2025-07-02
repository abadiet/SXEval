#ifndef SXEVAL_IOPERAND_HPP
#define SXEVAL_IOPERAND_HPP

#include "sxeval/AInstruction.hpp"

namespace sxeval {

/**
 * @brief The AOperand class is an abstract base class for operands.
 *
 * @tparam T The type of values handled by the SXEval library. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class AOperand : public AInstruction<T> {
public:
    /**
     * @brief Default constructor.
     *
     * @param result A reference to the result of the operand.
     */
    inline AOperand(T& result) : AInstruction<T>(result) {}

    /**
     * @brief Default destructor.
     */
    virtual ~AOperand() override = default;

};

} /* namespace sxeval */
#endif /* SXEVAL_IOPERAND_HPP */
