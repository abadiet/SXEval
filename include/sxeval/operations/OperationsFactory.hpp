
#ifndef SXEVAL_OPERATIONS_HPP
#define SXEVAL_OPERATIONS_HPP

#include "sxeval/AOperation.hpp"
#include "sxeval/operations/Addition.hpp"
#include "sxeval/operations/Subtraction.hpp"
#include "sxeval/operations/Multiplication.hpp"
#include "sxeval/operations/Division.hpp"
#include "sxeval/operations/Modulo.hpp"
#include "sxeval/operations/Exponentiation.hpp"
#include "sxeval/operations/Equal.hpp"
#include "sxeval/operations/NotEqual.hpp"
#include "sxeval/operations/Less.hpp"
#include "sxeval/operations/Greater.hpp"
#include "sxeval/operations/LessOrEqual.hpp"
#include "sxeval/operations/GreaterOrEqual.hpp"
#include "sxeval/operations/LogicalAnd.hpp"
#include "sxeval/operations/LogicalOr.hpp"
#include "sxeval/operations/LogicalNot.hpp"
#include "sxeval/operations/LogicalXor.hpp"
#include "sxeval/operations/LogicalXnor.hpp"
#include "sxeval/operations/LogicalNand.hpp"
#include "sxeval/operations/LogicalNor.hpp"
#include "sxeval/operations/AbsoluteValue.hpp"
#include "sxeval/operations/Average.hpp"
#include "sxeval/operations/Ceiling.hpp"
#include "sxeval/operations/Clamp.hpp"
#include "sxeval/operations/Expm1.hpp"
#include "sxeval/operations/Floor.hpp"
#include "sxeval/operations/Hypotenuse.hpp"
#include "sxeval/operations/NaturalLogarithm.hpp"
#include "sxeval/operations/Logarithm.hpp"
#include "sxeval/operations/Logarithm10.hpp"
#include "sxeval/operations/Logarithm1p.hpp"
#include "sxeval/operations/Logarithm2.hpp"
#include "sxeval/operations/LogarithmB.hpp"
#include "sxeval/operations/Maximum.hpp"
#include "sxeval/operations/Minimum.hpp"
#include "sxeval/operations/Round.hpp"
#include "sxeval/operations/SquareRoot.hpp"
#include "sxeval/operations/Truncate.hpp"
#include "sxeval/operations/ArcCosine.hpp"
#include "sxeval/operations/ArcCosh.hpp"
#include "sxeval/operations/ArcSine.hpp"
#include "sxeval/operations/ArcSinh.hpp"
#include "sxeval/operations/ArcTangent.hpp"
#include "sxeval/operations/ArcTangent2.hpp"
#include "sxeval/operations/ArcTanh.hpp"
#include "sxeval/operations/Cosine.hpp"
#include "sxeval/operations/Cosh.hpp"
#include "sxeval/operations/Sine.hpp"
#include "sxeval/operations/Sinh.hpp"
#include "sxeval/operations/Tangent.hpp"
#include "sxeval/operations/Tanh.hpp"
#include "sxeval/operations/DegreesToRadians.hpp"
#include "sxeval/operations/RadiansToDegrees.hpp"
#include "sxeval/operations/DegreesToGradians.hpp"
#include "sxeval/operations/GradiansToDegrees.hpp"
#include <memory>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <functional>
#include <sstream>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class OperationsFactory {
public:
    OperationsFactory();

    template <typename OP>
    void add();

    std::unique_ptr<AOperation<T>> create(const std::string& key,
        const std::vector<AInstruction<T>*> args);

private:
    std::unordered_map<std::string,
        const std::function<std::unique_ptr<AOperation<T>>(
        const std::vector<AInstruction<T>*>&)>> _operations;

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>

sxeval::operations::OperationsFactory<T>::OperationsFactory() {
    add<Addition<T>>();
    add<Subtraction<T>>();
    add<Multiplication<T>>();
    add<Division<T>>();
    add<Modulo<T>>();
    add<Exponentiation<T>>();
    add<Equal<T>>();
    add<NotEqual<T>>();
    add<Less<T>>();
    add<Greater<T>>();
    add<LessOrEqual<T>>();
    add<GreaterOrEqual<T>>();
    add<LogicalAnd<T>>();
    add<LogicalOr<T>>();
    add<LogicalNot<T>>();
    add<LogicalXor<T>>();
    add<LogicalXnor<T>>();
    add<LogicalNand<T>>();
    add<LogicalNor<T>>();
    add<AbsoluteValue<T>>();
    add<Average<T>>();
    add<Ceiling<T>>();
    add<Clamp<T>>();
    add<Expm1<T>>();
    add<Floor<T>>();
    add<Hypotenuse<T>>();
    add<NaturalLogarithm<T>>();
    add<Logarithm<T>>();
    add<Logarithm10<T>>();
    add<Logarithm1p<T>>();
    add<Logarithm2<T>>();
    add<LogarithmB<T>>();
    add<Maximum<T>>();
    add<Minimum<T>>();
    add<Round<T>>();
    add<SquareRoot<T>>();
    add<Truncate<T>>();
    add<ArcCosine<T>>();
    add<ArcCosh<T>>();
    add<ArcSine<T>>();
    add<ArcSinh<T>>();
    add<ArcTangent<T>>();
    add<ArcTangent2<T>>();
    add<ArcTanh<T>>();
    add<Cosine<T>>();
    add<Cosh<T>>();
    add<Sine<T>>();
    add<Sinh<T>>();
    add<Tangent<T>>();
    add<Tanh<T>>();
    add<DegreesToRadians<T>>();
    add<RadiansToDegrees<T>>();
    add<DegreesToGradians<T>>();
    add<GradiansToDegrees<T>>();
}

template <typename T>
template <typename OP>
void sxeval::operations::OperationsFactory<T>::add() {
    if constexpr (!(std::is_base_of<AOperation<T>, OP>::value)) {
        throw std::invalid_argument("OP must be derived from AOperation");
    }
    if (_operations.find(OP::KEY) != _operations.end()) {
        _operations.erase(OP::KEY);
    }
    const std::function<std::unique_ptr<AOperation<T>>(
        const std::vector<AInstruction<T>*>&)> f =
        [](const std::vector<AInstruction<T>*>& args) {
            const auto nargs = static_cast<int>(args.size());
            if (nargs < OP::ARITY_MIN) {
                std::ostringstream oss;
                oss << "Operation " << OP::KEY << " requires at least "
                    << OP::ARITY_MIN << " arguments";
                throw std::invalid_argument(oss.str());
            }
            if (OP::ARITY_MAX != AOperation<T>::UNLIMITED_ARITY
                && nargs > OP::ARITY_MAX)
            {
                std::ostringstream oss;
                oss << "Operation " << OP::KEY << " requires at most "
                    << OP::ARITY_MAX << " arguments";
                throw std::invalid_argument(oss.str());
            }
            return std::make_unique<OP>(args);
        };
    _operations.insert(std::make_pair(OP::KEY, f));
}

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::OperationsFactory<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{
    const auto it = _operations.find(key);
    if (it == _operations.end()) {
        throw std::invalid_argument("Unknown operation key: " + key);
    }
    return it->second(args);
}

#endif /* SXEVAL_OPERATIONS_HPP */
