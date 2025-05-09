#ifndef SXEVAL_OPERATIONS_SINH_HPP
#define SXEVAL_OPERATIONS_SINH_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Sinh : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "sinh";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Sinh(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Sinh<T>::execute() {
    this->_result = static_cast<T>(std::sinh(this->_args.front()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_SINH_HPP */
