#ifndef SXEVAL_OPERATIONS_ARCTANH_HPP
#define SXEVAL_OPERATIONS_ARCTANH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class ArcTanh : public AOperation<T> {
public:
    static constexpr const char *KEY = "atanh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline ArcTanh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::ArcTanh<T>::execute() {
    this->getResult() = static_cast<T>(std::atanh(this->getArgs().front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_ARCTANH_HPP */
