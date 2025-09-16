#ifndef SXEVAL_OPERATIONS_COSINE_HPP
#define SXEVAL_OPERATIONS_COSINE_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Cosine : public AOperation<T> {
public:
    static constexpr const char* KEY = "cos";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Cosine(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Cosine<T>::KEY;

template <typename T>
void sxeval::operations::Cosine<T>::execute() {
    this->_result = static_cast<T>(std::cos(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_COSINE_HPP */
