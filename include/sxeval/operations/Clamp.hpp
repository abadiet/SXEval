#ifndef SXEVAL_OPERATIONS_CLAMP_HPP
#define SXEVAL_OPERATIONS_CLAMP_HPP

#include "sxeval/AOperation.hpp"
#include <algorithm>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Clamp : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "clamp";
    static constexpr const int ARITY_MIN = 3;
    static constexpr const int ARITY_MAX = 3;

    inline Clamp(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Clamp<T>::execute() {
    this->_result = static_cast<T>(std::clamp(this->_args.front()->getResult(),
        this->_args[1]->getResult(), this->_args.back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_CLAMP_HPP */
