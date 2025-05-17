#ifndef SXEVAL_OPERATIONS_SINE_HPP
#define SXEVAL_OPERATIONS_SINE_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Sine : public AOperation<T> {
public:
    static constexpr const char *KEY = "sin";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Sine(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Sine<T>::execute() {
    this->getResult() = static_cast<T>(std::sin(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_SINE_HPP */
