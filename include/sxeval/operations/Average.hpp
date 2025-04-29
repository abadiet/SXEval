#ifndef SXEVAL_OPERATIONS_AVERAGE_HPP
#define SXEVAL_OPERATIONS_AVERAGE_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Average : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "avg";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline Average(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Average<T>::execute() {
    this->_result = static_cast<T>(0);
    for (const auto& arg : this->_args) {
        this->_result += arg->getResult();
    }
    this->_result /= static_cast<T>(this->_args.size());
}

#endif /* SXEVAL_OPERATIONS_AVERAGE_HPP */
