#ifndef SXEVAL_OPERATIONS_LOGARITHM_HPP
#define SXEVAL_OPERATIONS_LOGARITHM_HPP

#include "sxeval/AOperation.hpp"
#include <cmath>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Logarithm : public AOperation<T> {
public:
    static constexpr const char* KEY = "log";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    inline Logarithm(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
constexpr const char* sxeval::operations::Logarithm<T>::KEY;

template <typename T>
void sxeval::operations::Logarithm<T>::execute() {
    this->_result = static_cast<T>(std::log(this->_args.front().get()));
}

#endif /* SXEVAL_OPERATIONS_LOGARITHM_HPP */
