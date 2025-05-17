#ifndef SXEVAL_OPERATIONS_SUBTRACTION_HPP
#define SXEVAL_OPERATIONS_SUBTRACTION_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Subtraction : public AOperation<T> {
public:
    static constexpr const char *KEY = "-";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Subtraction(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Subtraction<T>::execute() {
    this->getResult() = this->getArgs().front()->getResult();
    for (size_t i = 1; i < this->getArgs().size(); ++i) {
        this->getResult() -= this->getArgs()[i]->getResult();
    }
}

#endif /* SXEVAL_OPERATIONS_SUBTRACTION_HPP */
