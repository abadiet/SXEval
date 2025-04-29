#ifndef SXEVAL_OPERATIONS_HYPOTENUSE_HPP
#define SXEVAL_OPERATIONS_HYPOTENUSE_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Hypotenuse : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "hypot";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = 2;

    inline Hypotenuse(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Hypotenuse<T>::execute() {
    this->_result = static_cast<T>(std::hypot(this->_args.front()->getResult(),
        this->_args.back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_HYPOTENUSE_HPP */
