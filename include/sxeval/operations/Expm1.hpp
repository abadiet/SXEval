#ifndef SXEVAL_OPERATIONS_EXPM1_HPP
#define SXEVAL_OPERATIONS_EXPM1_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Expm1 : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "expm1";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Expm1(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Expm1<T>::execute() {
    this->_result = static_cast<T>(std::expm1(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_EXPM1_HPP */
