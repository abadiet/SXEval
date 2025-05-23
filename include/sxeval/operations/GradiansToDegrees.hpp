#ifndef SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP
#define SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class GradiansToDegrees : public AOperation<T> {
public:
    static constexpr const char *KEY = "grad2deg";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline GradiansToDegrees(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::GradiansToDegrees<T>::execute() {
    this->getResult() = this->getArgs()[0]->getResult() * static_cast<T>(0.9);
}

#endif /* SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP */
