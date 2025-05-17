#ifndef SXEVAL_OPERATIONS_NOTEQUAL_HPP
#define SXEVAL_OPERATIONS_NOTEQUAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class NotEqual : public AOperation<T> {
public:
    static constexpr const char *KEY = "!=";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline NotEqual(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::NotEqual<T>::execute() {
    this->getResult() = static_cast<T>(1);
    size_t i = 1, j;
    bool verif = true;
    while (verif && i < this->getArgs().size()) {
        j = 0;
        while (verif && j < i) {
            verif = sxeval::NotEqual(this->getArgs()[j]->getResult(),
                this->getArgs()[i]->getResult());
            ++j;
        }
        ++i;
    }
    if (verif) {
        this->getResult() = static_cast<T>(1);
    }
    else {
        this->getResult() = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_NOTEQUAL_HPP */
