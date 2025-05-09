#ifndef SXEVAL_OPERATIONS_MODULO_HPP
#define SXEVAL_OPERATIONS_MODULO_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/utils.hpp"


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations;

template <typename T>
class Modulo : public AOperation<T> {
public:
    void execute() override;

    std::string toString() const override { return KEY; }

protected:
    static constexpr const char *KEY = "%";
    static constexpr const int ARITY_MIN = 2;
    static constexpr const int ARITY_MAX = Operations<T>::UNLIMITED_ARITY;

    inline Modulo(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {}

    friend class Operations<T>;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::Modulo<T>::execute() {
    this->_result = this->_args.front()->getResult();
    for (size_t i = 1; i < this->_args.size(); ++i) {
        this->_result = static_cast<T>(sxeval::Modulo<T>(this->_result,
            this->_args[i]->getResult()));
    }
}

#endif /* SXEVAL_OPERATIONS_MODULO_HPP */
