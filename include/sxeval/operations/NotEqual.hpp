#ifndef SXEVAL_OPERATIONS_NOTEQUAL_HPP
#define SXEVAL_OPERATIONS_NOTEQUAL_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class NotEqual : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "!=";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline NotEqual(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::NotEqual<T>::execute() {
    this->_result = static_cast<T>(1);
    size_t i = 1, j;
    bool verif = true;
    while (verif && i < this->_args.size()) {
        j = 0;
        while (verif && j < i) {
            verif = sxeval::NotEqual(this->_args[j]->getResult(),
                this->_args[i]->getResult());
            ++j;
        }
        ++i;
    }
    if (verif) {
        this->_result = static_cast<T>(1);
    }
    else {
        this->_result = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_NOTEQUAL_HPP */
