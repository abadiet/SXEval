#ifndef SXEVAL_OPERATIONS_GREATEROREQUAL_HPP
#define SXEVAL_OPERATIONS_GREATEROREQUAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class GreaterOrEqual : public AOperation<T> {
public:
    static constexpr const char *KEY = ">=";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline GreaterOrEqual(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::GreaterOrEqual<T>::execute() {
    this->getResult() = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->getArgs().size()) {
        verif = sxeval::GreaterOrEqual(this->getArgs()[i]->getResult(),
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

#endif /* SXEVAL_OPERATIONS_GREATEROREQUAL_HPP */
