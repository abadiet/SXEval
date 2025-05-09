#ifndef SXEVAL_ENCASPULATED_VARIABLE_HPP
#define SXEVAL_ENCASPULATED_VARIABLE_HPP

#include "sxeval/AOperand.hpp"
#include <functional>

namespace sxeval {

template <typename T>
class EncapsulatedVariable : public AOperand<T> {
public:
    inline EncapsulatedVariable(const std::function<T(void)> get,
        const std::string& name) :
        AOperand<T>(_var), _get(get), _name(name) {}

    inline void retrieve() { _var = _get(); }

    inline std::string toString() const override { return _name; }

private:
    T _var;
    const std::function<T(void)> _get;
    const std::string _name;

};

} /* namespace sxeval */
#endif /* SXEVAL_ENCASPULATED_VARIABLE_HPP */
