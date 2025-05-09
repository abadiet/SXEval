#ifndef SXEVAL_OPERATIONS_ARCTANH_HPP
#define SXEVAL_OPERATIONS_ARCTANH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class ArcTanh : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "atanh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline ArcTanh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::ArcTanh<T>::execute() {
    this->_result = static_cast<T>(std::atanh(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_ARCTANH_HPP */
