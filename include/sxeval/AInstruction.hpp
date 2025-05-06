#ifndef SXEVAL_AINSTRUCTION_HPP
#define SXEVAL_AINSTRUCTION_HPP

namespace sxeval {

template <typename T>
class AInstruction {
public:
    inline AInstruction(T& result) : _result(result) {}
    virtual ~AInstruction() = default;

    inline T getResult() const { return _result; }

private:
    T& _result;

};

} /* namespace sxeval */
#endif /* SXEVAL_AINSTRUCTION_HPP */
