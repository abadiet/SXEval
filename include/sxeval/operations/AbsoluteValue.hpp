#ifndef SXEVAL_OPERATIONS_ABSOLUTEVALUE_HPP
#define SXEVAL_OPERATIONS_ABSOLUTEVALUE_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class AbsoluteValue : public AOperation<T> {
public:
    static constexpr const char* KEY = "abs";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline AbsoluteValue(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::AbsoluteValue<T>::KEY;

template <typename T>
void sxeval::operations::AbsoluteValue<T>::execute() {
    this->_result = static_cast<T>(sxeval::Absolute<T>(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_ABSOLUTEVALUE_HPP */
