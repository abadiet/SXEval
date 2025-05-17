#ifndef SXEVAL_AOPERATION_HPP
#define SXEVAL_AOPERATION_HPP

#include "sxeval/AInstruction.hpp"
#include <vector>


namespace sxeval {

template <typename T>
class AOperation : public AInstruction<T> {
public:
    static constexpr const int UNLIMITED_ARITY = -1;

    inline AOperation(const std::vector<AInstruction<T>*>& args) 
        : AInstruction<T>(_result), _args(args) {}
    inline AOperation(const AOperation& other)
        : AInstruction<T>(_result), _result(other._result),
        _args(other._args) {}
    virtual ~AOperation() override = default;

    inline const std::vector<AInstruction<T>*>& getArgs() const { return _args; }
    inline T& getResult() { return _result; }

    virtual void execute() = 0;

private:
    T _result = T();
    const std::vector<AInstruction<T>*> _args;

};

} /* namespace sxeval */
#endif /* SXEVAL_AOPERATION_HPP */
