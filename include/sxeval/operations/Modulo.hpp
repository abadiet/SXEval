#ifndef SXEVAL_OPERATIONS_MODULO_HPP
#define SXEVAL_OPERATIONS_MODULO_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Modulo : public AOperation<T> {
public:
    static constexpr const char* KEY = "%";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = AOperation<T>::UNLIMITED_ARITY;

    inline Modulo(const std::vector<IInstruction<T>*>& args) :
        AOperation<T>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Modulo<T>::execute() {
    this->_result = this->_args.front();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(sxeval::Modulo<T>(this->_result,
            this->_args[i].get()));
    }
}

#endif /* SXEVAL_OPERATIONS_MODULO_HPP */
