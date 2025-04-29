#ifndef SXEVAL_OPERATIONS_DEGREESTOGRADIANS_HPP
#define SXEVAL_OPERATIONS_DEGREESTOGRADIANS_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class DegreesToGradians : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "deg2grad";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline DegreesToGradians(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::DegreesToGradians<T>::execute() {
    this->_result = this->_args[0]->getResult() * static_cast<T>(10.0 / 9.0);
}

#endif /* SXEVAL_OPERATIONS_DEGREESTOGRADIANS_HPP */
