#ifndef SXEVAL_OPERATIONS_LOGARITHMB_HPP
#define SXEVAL_OPERATIONS_LOGARITHMB_HPP

#include "sxeval/AOperation.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class LogarithmB : public AOperation<T> {
public:
    static constexpr const char *KEY = "logB";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = 2;

    inline LogarithmB(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::LogarithmB<T>::execute() {
    this->getResult() = static_cast<T>(std::log(this->getArgs().front()->getResult()) /
        std::log(this->getArgs().back()->getResult()));
}

#endif /* SXEVAL_OPERATIONS_LOGARITHMB_HPP */
