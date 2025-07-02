#ifndef SXEVAL_AOPERATION_HPP
#define SXEVAL_AOPERATION_HPP

#include "sxeval/AInstruction.hpp"
#include <vector>


namespace sxeval {

/**
 * @brief The AOperation class is an abstract base class for operations in the
 * SXEval library.
 *
 * It represents an operation that can be executed with a variable number of
 * arguments. The result of the operation is stored in a member variable.
 *
 * @tparam T The type of values handled by the SXEval library. The supported
 * types are int, signed char, short int, long int, unsigned int, unsigned char,
 * unsigned long int, float, double and long double.
 */
template <typename T>
class AOperation : public AInstruction<T> {
public:
    /**
     * @brief The value for an unlimited number of arguments. 
     */
    static constexpr const int UNLIMITED_ARITY = -1;

    /**
     * @brief Constructor that initializes the operation.
     */
    inline AOperation(const std::vector<AInstruction<T>*>& args) 
        : AInstruction<T>(_result), _args(args) {}

    /**
     * @brief Copy constructor.
     *
     * @param other The operation to copy.
     */
    inline AOperation(const AOperation& other)
        : AInstruction<T>(_result), _result(other._result),
        _args(other._args) {}

    /**
     * @brief Default destructor.
     */
    virtual ~AOperation() override = default;

    /**
     * @brief Return the arguments of the operation.
     *
     * @return A vector of pointers to the arguments of the operation.
     */
    inline const std::vector<AInstruction<T>*>& getArgs() const { return _args; }

    /**
     * @brief Get the result of the operation.
     *
     * @return A reference to the result of the operation.
     */
    inline T& getResult() { return _result; }

    /**
     * @brief Execute the operation.
     *
     * This method must be implemented by derived classes to perform the
     * specific operation logic.
     */
    virtual void execute() = 0;

private:
    T _result = T();
    const std::vector<AInstruction<T>*> _args;

};

} /* namespace sxeval */
#endif /* SXEVAL_AOPERATION_HPP */
