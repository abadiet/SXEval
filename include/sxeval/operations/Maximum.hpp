#ifndef SXEVAL_OPERATIONS_MAXIMUM_HPP
#define SXEVAL_OPERATIONS_MAXIMUM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>
#include <limits>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Maximum : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "max";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline Maximum(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Maximum<T>::execute() {
    this->_result = this->_args.front()->getResult();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(std::max(this->_result,
            this->_args[i]->getResult()));
    }
}

#endif /* SXEVAL_OPERATIONS_MAXIMUM_HPP */
