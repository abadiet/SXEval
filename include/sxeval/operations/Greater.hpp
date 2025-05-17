#ifndef SXEVAL_OPERATIONS_GREATER_HPP
#define SXEVAL_OPERATIONS_GREATER_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Greater : public AOperation<T> {
public:
    static constexpr const char *KEY = ">";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Greater(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Greater<T>::execute() {
    this->getResult() = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->getArgs().size()) {
        verif = sxeval::Greater(this->getArgs()[i]->getResult(),
            this->getArgs()[i + 1]->getResult());
        ++i;
    }
    if (verif) {
        this->getResult() = static_cast<T>(1);
    }
    else {
        this->getResult() = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_GREATER_HPP */
