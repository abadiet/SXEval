#ifndef SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP
#define SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class GradiansToDegrees : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "grad2deg";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline GradiansToDegrees(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::GradiansToDegrees<T>::execute() {
    this->_result = this->_args[0]->getResult() * static_cast<T>(0.9);
}

#endif /* SXEVAL_OPERATIONS_GRADIANSTODEGREES_HPP */
