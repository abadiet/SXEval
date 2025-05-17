#ifndef SXEVAL_OPERATIONS_CEILING_HPP
#define SXEVAL_OPERATIONS_CEILING_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Ceiling : public AOperation<T> {
public:
    static constexpr const char *KEY = "ceil";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Ceiling(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Ceiling<T>::execute() {
    this->getResult() = static_cast<T>(std::ceil(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_CEILING_HPP */
