#ifndef SXEVAL_OPERATIONS_ARCCOSH_HPP
#define SXEVAL_OPERATIONS_ARCCOSH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class ArcCosh : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "acosh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline ArcCosh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::ArcCosh<T>::execute() {
    this->_result = static_cast<T>(std::acosh(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_ARCCOSH_HPP */
