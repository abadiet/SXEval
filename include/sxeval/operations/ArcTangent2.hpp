#ifndef SXEVAL_OPERATIONS_ARCTANGENT2_HPP
#define SXEVAL_OPERATIONS_ARCTANGENT2_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class ArcTangent2 : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "atan2";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = 2;

    inline ArcTangent2(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::ArcTangent2<T>::execute() {
    this->_result = static_cast<T>(std::atan2(this->_args.front()->getResult(),
        this->_args.back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_ARCTANGENT2_HPP */
