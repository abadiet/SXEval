#ifndef SXEVAL_OPERATIONS_CLAMP_HPP
#define SXEVAL_OPERATIONS_CLAMP_HPP

#include "sxeval/AOperation.hpp"
#include <algorithm>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Clamp : public AOperation<T> {
public:
    static constexpr const char *KEY = "clamp";
    static constexpr const int ARITY_MIN = 3;
    static constexpr const int ARITY_MAX = 3;

    inline Clamp(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Clamp<T>::execute() {
    this->getResult() = static_cast<T>(std::clamp(this->getArgs().front()->getResult(),
        this->getArgs()[1]->getResult(), this->getArgs().back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_CLAMP_HPP */
