#ifndef SXEVAL_OPERATIONS_LOGICALXNOR_HPP
#define SXEVAL_OPERATIONS_LOGICALXNOR_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class LogicalXnor : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "xnor";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline LogicalXnor(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::LogicalXnor<T>::execute() {
    this->_result = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->_args.size()) {
        verif = sxeval::LogicalXnor(this->_args[i]->getResult(),
            this->_args[i + 1]->getResult());
        ++i;
    }
    if (verif) {
        this->_result = static_cast<T>(1);
    }
    else {
        this->_result = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_LOGICALXNOR_HPP */
