#ifndef SXEVAL_AINSTRUCTION_HPP
#define SXEVAL_AINSTRUCTION_HPP

#include <string>


/* DEFINITIONS */

namespace sxeval {

template <typename T>
class AInstruction {
public:
    inline AInstruction(T& result) : _result(result) {}
    virtual ~AInstruction() = default;

    inline T getResult() const { return _result; }

    virtual std::string toString() const = 0;

private:
    T& _result;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const AInstruction<T>& obj) {
   return os << obj.toString();
}

} /* namespace sxeval */
#endif /* SXEVAL_AINSTRUCTION_HPP */
