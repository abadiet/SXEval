#ifndef SXEVAL_OPERATIONS_LOGICALNOT_HPP
#define SXEVAL_OPERATIONS_LOGICALNOT_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class LogicalNot : public AOperation<T> {
public:
    static constexpr const char* KEY = "not";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline LogicalNot(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::LogicalNot<T>::KEY;

template <typename T>
void sxeval::operations::LogicalNot<T>::execute() {
    this->_result = static_cast<T>(
        sxeval::LogicalNot(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_LOGICALNOT_HPP */
