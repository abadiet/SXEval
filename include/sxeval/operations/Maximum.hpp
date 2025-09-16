#ifndef SXEVAL_OPERATIONS_MAXIMUM_HPP
#define SXEVAL_OPERATIONS_MAXIMUM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Maximum : public AOperation<T> {
public:
    static constexpr const char* KEY = "max";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Maximum(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Maximum<T>::execute() {
    this->_result = this->_args.front();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(std::max(this->_result,
            this->_args[i].get()));
    }
}

#endif /* SXEVAL_OPERATIONS_MAXIMUM_HPP */
