#ifndef SXEVAL_OPERATIONS_SINH_HPP
#define SXEVAL_OPERATIONS_SINH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Sinh : public AOperation<T> {
public:
    static constexpr const char* KEY = "sinh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Sinh(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Sinh<T>::execute() {
    this->_result = static_cast<T>(std::sinh(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_SINH_HPP */
