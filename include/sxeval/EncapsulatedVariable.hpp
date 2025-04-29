#ifndef SXEVAL_ENCASPULATED_VARIABLE_HPP
#define SXEVAL_ENCASPULATED_VARIABLE_HPP

#include "sxeval/AOperand.hpp"
#include <functional>

namespace sxeval {

template <typename T>
class EncapsulatedVariable : public AOperand<T> {
public:
    inline EncapsulatedVariable(const std::function<T(void)> get) :
        AOperand<T>(_var), _get(get) {}

    inline void retrieve() {
        _var = _get();
    }

private:
    T _var;
    const std::function<T(void)> _get;

};

} /* namespace sxeval */
#endif /* SXEVAL_ENCASPULATED_VARIABLE_HPP */
