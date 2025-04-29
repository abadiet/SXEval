#ifndef SXEVAL_OPERATIONS_TANH_HPP
#define SXEVAL_OPERATIONS_TANH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Tanh : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "tanh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Tanh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Tanh<T>::execute() {
    this->_result = static_cast<T>(std::tanh(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_TANH_HPP */
