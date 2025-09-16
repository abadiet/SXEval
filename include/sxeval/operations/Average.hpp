#ifndef SXEVAL_OPERATIONS_AVERAGE_HPP
#define SXEVAL_OPERATIONS_AVERAGE_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Average : public AOperation<T> {
public:
    static constexpr const char* KEY = "avg";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Average(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Average<T>::KEY;

template <typename T>
void sxeval::operations::Average<T>::execute() {
    this->_result = static_cast<T>(0);
    for (const auto& arg : this->_args) {
        this->_result += arg.get();
    }
    this->_result /= static_cast<T>(this->_args.size());
}

#endif /* SXEVAL_OPERATIONS_AVERAGE_HPP */
