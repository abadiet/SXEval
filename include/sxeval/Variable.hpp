#ifndef SXEVAL_VARIABLE_HPP
#define SXEVAL_VARIABLE_HPP

#include "sxeval/AOperand.hpp"

namespace sxeval {

template <typename T>
class Variable : public AOperand<T> {
public:
    inline Variable(T& var, const std::string& name) : AOperand<T>(var),
        _name(name) {}

    inline std::string toString() const override { return _name; }

private:
    const std::string _name;

};

} /* namespace sxeval */
#endif /* SXEVAL_VARIABLE_HPP */
