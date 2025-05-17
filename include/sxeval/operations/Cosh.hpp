#ifndef SXEVAL_OPERATIONS_COSH_HPP
#define SXEVAL_OPERATIONS_COSH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Cosh : public AOperation<T> {
public:
    static constexpr const char *KEY = "cosh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Cosh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Cosh<T>::execute() {
    this->getResult() = static_cast<T>(std::cosh(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_COSH_HPP */
