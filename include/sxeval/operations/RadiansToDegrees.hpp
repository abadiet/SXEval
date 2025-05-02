#ifndef SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP
#define SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class RadiansToDegrees : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "rad2deg";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline RadiansToDegrees(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::RadiansToDegrees<T>::execute() {
    this->_result = this->_args[0]->getResult() * static_cast<T>(180.0 / SXEVAL_PI);
}

#endif /* SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP */
