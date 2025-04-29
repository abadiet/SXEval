#ifndef SXEVAL_OPERATIONS_SQUAREROOT_HPP
#define SXEVAL_OPERATIONS_SQUAREROOT_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class SquareRoot : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "sqrt";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline SquareRoot(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::SquareRoot<T>::execute() {
    this->_result = static_cast<T>(std::sqrt(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_SQUAREROOT_HPP */
