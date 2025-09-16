#ifndef SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP
#define SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class RadiansToDegrees : public AOperation<T> {
public:
    static constexpr const char* KEY = "rad2deg";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline RadiansToDegrees(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::RadiansToDegrees<T>::KEY;

template <typename T>
void sxeval::operations::RadiansToDegrees<T>::execute() {
    this->_result = this->_args.front().get() *
        static_cast<T>(180.0 / SXEVAL_PI);
}

#endif /* SXEVAL_OPERATIONS_RADIANSTODEGREES_HPP */
