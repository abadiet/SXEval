#ifndef SXEVAL_OPERATIONS_DIVISION_HPP
#define SXEVAL_OPERATIONS_DIVISION_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Division : public AOperation<T> {
public:
    static constexpr const char* KEY = "/";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Division(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Division<T>::KEY;

template <typename T>
void sxeval::operations::Division<T>::execute() {
    this->_result = this->_args.front();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result /= this->_args[i].get();
    }
}

#endif /* SXEVAL_OPERATIONS_DIVISION_HPP */
