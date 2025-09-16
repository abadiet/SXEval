#ifndef SXEVAL_IINSTRUCTION_HPP
#define SXEVAL_IINSTRUCTION_HPP

#include <string>


/* DEFINITIONS */

namespace sxeval {

/**
 * @brief The IInstruction class is an interface for any instructions.
 *
 * It represents an instruction that can be executed and has a result.
 *
 * @tparam T The type of values handled by the SXEval library. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class IInstruction {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~IInstruction() = default;

    /**
     * @brief Get a reference to the result of the instruction.
     * 
     * @return A reference result of the instruction.
     */
    virtual T& getResult() = 0;

    /**
     * @brief String representation of the instruction.
     *
     * @return A string representation of the instruction.
     */
    virtual std::string toString() const = 0;

};

/**
 * @brief Output stream operator for AInstruction.
 * @param os The output stream.
 * @param obj The AInstruction object to output.
 * @return The output stream.
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const IInstruction<T>& obj) {
   return os << obj.toString();
}

} /* namespace sxeval */
#endif /* SXEVAL_IINSTRUCTION_HPP */
