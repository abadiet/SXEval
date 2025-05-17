#ifndef SXEVAL_OPERATIONS_LOGARITHM10_HPP
#define SXEVAL_OPERATIONS_LOGARITHM10_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Logarithm10 : public AOperation<T> {
public:
    static constexpr const char *KEY = "log10";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Logarithm10(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Logarithm10<T>::execute() {
    this->getResult() = static_cast<T>(std::log10(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_LOGARITHM10_HPP */
