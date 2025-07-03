#ifndef SXEVAL_OPERATIONS_EXP_HPP
#define SXEVAL_OPERATIONS_EXP_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Exp : public AOperation<T> {
public:
    static constexpr const char* KEY = "exp";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Exp(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Exp<T>::execute() {
    this->getResult() = static_cast<T>(std::exp(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_EXP_HPP */
