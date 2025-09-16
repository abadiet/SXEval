#ifndef SXEVAL_AOPERATION_HPP
#define SXEVAL_AOPERATION_HPP

#include "sxeval/IInstruction.hpp"
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
class AOperation : public virtual IInstruction<T> {
public:
    /**
     * @brief The value for an unlimited number of arguments. 
     */
    static constexpr const int UNLIMITED_ARITY = -1;

    /**
     * @brief Default key for the operation.
     */
    static constexpr const char* KEY = "AOperation";

    /**
     * @brief Default minimum number of arguments for the operation.
     */
    static constexpr const int ARITY_MIN = 0;

    /**
     * @brief Default maximum number of arguments for the operation.
     */
    static constexpr const int ARITY_MAX = UNLIMITED_ARITY;

    /**
     * @brief Constructor that initializes the operation.
     */
    AOperation(const std::vector<IInstruction<T>*>& args);

    /**
     * @brief Copy constructor.
     *
     * @param other The operation to copy.
     */
    inline AOperation(const AOperation& other)
        : _result(other._result), _args(other._args) {}

    /**
     * @brief Default destructor.
     */
    virtual ~AOperation() override = default;

    /**
     * @brief Get the result of the operation.
     *
     * @return A reference to the result of the operation.
     */
    inline T& getResult() override { return _result; }

    /**
     * @brief Execute the operation.
     *
     * This method must be implemented by derived classes to perform the
     * specific operation logic.
     */
    virtual void execute() = 0;

protected:
    T _result;
    std::vector<std::reference_wrapper<T>> _args;

};

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
sxeval::AOperation<T>::AOperation(const std::vector<IInstruction<T>*>& args) {
    for (const auto& arg : args) {
        _args.push_back(arg->getResult());
    }
}

#endif /* SXEVAL_AOPERATION_HPP */
