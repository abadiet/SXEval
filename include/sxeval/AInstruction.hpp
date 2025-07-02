#ifndef SXEVAL_AINSTRUCTION_HPP
#define SXEVAL_AINSTRUCTION_HPP

#include <string>


/* DEFINITIONS */

namespace sxeval {

/**
 * @brief The AInstruction class is an abstract base class for any instructions.
 *
 * It represents an instruction that can be executed and has a result.
 * The result is stored in a member variable.
 *
 * @tparam T The type of values handled by the SXEval library. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class AInstruction {
public:
    /**
     * @brief Default constructor.
     * @param result A reference to the result of the instruction.
     */
    inline AInstruction(T& result) : _result(result) {}

    /**
     * @brief Default destructor.
     */
    virtual ~AInstruction() = default;

    /**
     * @brief Get the result of the instruction.
     * @return The result of the instruction.
     */
    inline T getResult() const { return _result; }

    /**
     * @brief String representation of the instruction.
     *
     * @return A string representation of the instruction.
     */
    virtual std::string toString() const = 0;

private:
    T& _result;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const AInstruction<T>& obj) {
   return os << obj.toString();
}

} /* namespace sxeval */
#endif /* SXEVAL_AINSTRUCTION_HPP */
