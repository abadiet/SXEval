#ifndef SXEVAL_OPERATIONS_LOGARITHMB_HPP
#define SXEVAL_OPERATIONS_LOGARITHMB_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class LogarithmB : public AOperation<T> {
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "logB";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = 2;

    inline LogarithmB(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::LogarithmB<T>::execute() {
    this->_result = static_cast<T>(std::log(this->_args.front()->getResult()) /
        std::log(this->_args.back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_LOGARITHMB_HPP */
