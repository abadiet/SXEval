
#ifndef SXEVAL_OPERATIONS_HPP
#define SXEVAL_OPERATIONS_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/operations/Addition.hpp"
#include <vector>
#include <memory>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations {
public:
    static constexpr const int UNLIMITED_ARITY = -1;

    Operations() = delete;
    Operations(const Operations&) = delete;
    Operations& operator=(const Operations&) = delete;
    Operations(Operations&&) = delete;
    Operations& operator=(Operations&&) = delete;
    ~Operations() = delete;

    static std::unique_ptr<AOperation<T>> create(const std::string& key,
        const std::vector<AInstruction<T>*> args);

private:
    static void checkArity(const std::string& key, int nArgs, int arityMin,
        int arityMax);

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::Operations<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{
    if (key == sxeval::operations::Addition<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Addition<T>::ARITY_MIN,
            sxeval::operations::Addition<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Addition<T>>(
            sxeval::operations::Addition<T>(args));
    }
    throw std::invalid_argument("Unknown operation key: " + key);
}

template <typename T>
void sxeval::operations::Operations<T>::checkArity(const std::string& key,
    int nArgs, int arityMin, int arityMax)
{
    if (nArgs < arityMin) {
        throw std::invalid_argument("Operation " + key + " requires at least "
            + std::to_string(arityMin) + " arguments");
    }
    if (arityMax != UNLIMITED_ARITY && nArgs > arityMax) {
        throw std::invalid_argument("Operation " + key + " requires at most "
            + std::to_string(arityMax) + " arguments");
    }
}

#endif /* SXEVAL_OPERATIONS_HPP */
