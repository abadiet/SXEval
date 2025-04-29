#ifndef SXEVAL_OPERATIONS_MINIMUM_HPP
#define SXEVAL_OPERATIONS_MINIMUM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>
#include <limits>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Minimum : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "min";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline Minimum(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Minimum<T>::execute() {
    this->_result = this->_args.front()->getResult();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(std::min(this->_result,
            this->_args[i]->getResult()));
    }
}

#endif /* SXEVAL_OPERATIONS_MINIMUM_HPP */
