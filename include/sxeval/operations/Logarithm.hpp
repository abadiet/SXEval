#ifndef SXEVAL_OPERATIONS_LOGARITHM_HPP
#define SXEVAL_OPERATIONS_LOGARITHM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Logarithm : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "log";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Logarithm(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Logarithm<T>::execute() {
    this->_result = static_cast<T>(std::log(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_LOGARITHM_HPP */
