#ifndef SXEVAL_OPERATIONS_MAXIMUM_HPP
#define SXEVAL_OPERATIONS_MAXIMUM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Maximum : public AOperation<T> {
public:
    static constexpr const char *KEY = "max";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Maximum(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Maximum<T>::execute() {
    this->getResult() = this->getArgs().front()->getResult();
    for (size_t i = 1; i < this->getArgs().size(); ++i) {
        this->getResult() = static_cast<T>(std::max(this->getResult(),
            this->getArgs()[i]->getResult()));
    }
}

#endif /* SXEVAL_OPERATIONS_MAXIMUM_HPP */
