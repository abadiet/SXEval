#ifndef SXEVAL_OPERATIONS_ARCTANGENT2_HPP
#define SXEVAL_OPERATIONS_ARCTANGENT2_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class ArcTangent2 : public AOperation<T> {
public:
    static constexpr const char *KEY = "atan2";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = 2;

    inline ArcTangent2(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::ArcTangent2<T>::execute() {
    this->getResult() = static_cast<T>(std::atan2(this->getArgs().front()->getResult(),
        this->getArgs().back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_ARCTANGENT2_HPP */
