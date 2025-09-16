#ifndef SXEVAL_OPERATIONS_EXP_HPP
#define SXEVAL_OPERATIONS_EXP_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Exp : public AOperation<T> {
public:
    static constexpr const char* KEY = "exp";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Exp(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Exp<T>::KEY;

template <typename T>
void sxeval::operations::Exp<T>::execute() {
    this->_result = static_cast<T>(std::exp(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_EXP_HPP */
