#ifndef SXEVAL_OPERATIONS_LOGICALOR_HPP
#define SXEVAL_OPERATIONS_LOGICALOR_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class LogicalOr : public AOperation<T> {
public:
    static constexpr const char* KEY = "or";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline LogicalOr(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::LogicalOr<T>::KEY;

template <typename T>
void sxeval::operations::LogicalOr<T>::execute() {
    this->_result = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->_args.size()) {
        verif = sxeval::LogicalOr(this->_args[i].get(),
            this->_args[i + 1].get());
        ++i;
    }
    if (verif) {
        this->_result = static_cast<T>(1);
    }
    else {
        this->_result = static_cast<T>(0);
    }
}

#endif /* SXEVAL_OPERATIONS_LOGICALOR_HPP */
