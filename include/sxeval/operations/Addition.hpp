#ifndef SXEVAL_OPERATIONS_ADDITION_HPP
#define SXEVAL_OPERATIONS_ADDITION_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Addition : public AOperation<T> {
public:
    static constexpr const char* KEY = "+";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Addition(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Addition<T>::execute() {
    this->_result = this->_args.front();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result += this->_args[i].get();
    }
}

#endif /* SXEVAL_OPERATIONS_ADDITION_HPP */
