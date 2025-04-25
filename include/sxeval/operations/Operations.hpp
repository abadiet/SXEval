
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

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::Operations<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{
    if (key == sxeval::operations::Addition<T>::KEY)
        return std::make_unique<sxeval::operations::Addition<T>>(
            sxeval::operations::Addition<T>(args));
    throw std::invalid_argument("Unknown operation key: " + key);
}


#endif /* SXEVAL_OPERATIONS_HPP */
