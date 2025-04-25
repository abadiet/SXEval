#ifndef SXEVAL_OPERATIONS_ADDITION_HPP
#define SXEVAL_OPERATIONS_ADDITION_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Addition : public AOperation<T> {
public:
    static constexpr const char *KEY = "+";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline Addition(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Addition<T>::execute() {
    this->_result = 0;
    for (const auto& arg : this->_args) {
       this->_result += arg->getResult();
    }
}


#endif /* SXEVAL_OPERATIONS_ADDITION_HPP */
