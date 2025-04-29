#ifndef SXEVAL_OPERATIONS_COSINE_HPP
#define SXEVAL_OPERATIONS_COSINE_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Cosine : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "cos";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Cosine(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Cosine<T>::execute() {
    this->_result = static_cast<T>(std::cos(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_COSINE_HPP */
