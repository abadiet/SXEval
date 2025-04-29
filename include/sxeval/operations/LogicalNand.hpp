#ifndef SXEVAL_OPERATIONS_LOGICALNAND_HPP
#define SXEVAL_OPERATIONS_LOGICALNAND_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class LogicalNand : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "nand";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline LogicalNand(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::LogicalNand<T>::execute() {
    this->_result = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif) {
        verif = sxeval::LogicalNand(this->_args[i + 1]->getResult(),
            this->_args[i]->getResult());
        ++i;
    }
    if (verif) {
        this->_result = static_cast<T>(1);
    }
    else {
        this->_result = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_LOGICALNAND_HPP */
