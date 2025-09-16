#ifndef SXEVAL_OPERATIONS_LOGICALNOR_HPP
#define SXEVAL_OPERATIONS_LOGICALNOR_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class LogicalNor : public AOperation<T> {
public:
    static constexpr const char* KEY = "nor";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline LogicalNor(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::LogicalNor<T>::KEY;

template <typename T>
void sxeval::operations::LogicalNor<T>::execute() {
    this->_result = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->_args.size()) {
        verif = sxeval::LogicalNor(this->_args[i].get(),
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

#endif /* SXEVAL_OPERATIONS_LOGICALNOR_HPP */
