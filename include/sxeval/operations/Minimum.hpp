#ifndef SXEVAL_OPERATIONS_MINIMUM_HPP
#define SXEVAL_OPERATIONS_MINIMUM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Minimum : public AOperation<T> {
public:
    static constexpr const char* KEY = "min";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Minimum(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Minimum<T>::KEY;

template <typename T>
void sxeval::operations::Minimum<T>::execute() {
    this->_result = this->_args.front();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(std::min(this->_result,
            this->_args[i].get()));
    }
}

#endif /* SXEVAL_OPERATIONS_MINIMUM_HPP */
