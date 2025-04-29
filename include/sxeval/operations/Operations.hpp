
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
#include <vector>
#include <memory>


/* DEFINITIONS */

namespace sxeval {
namespace operations {

template <typename T>
class Operations {
public:
    static constexpr const int UNLIMITED_ARITY = -1;

    Operations() = delete;
    Operations(const Operations&) = delete;
    Operations& operator=(const Operations&) = delete;
    Operations(Operations&&) = delete;
    Operations& operator=(Operations&&) = delete;
    ~Operations() = delete;

    static std::unique_ptr<AOperation<T>> create(const std::string& key,
        const std::vector<AInstruction<T>*> args);

private:
    static void checkArity(const std::string& key, int nArgs, int arityMin,
        int arityMax);

};

} /* namespace operations */
} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::Operations<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{
    if (key == sxeval::operations::Addition<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Addition<T>::ARITY_MIN,
            sxeval::operations::Addition<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Addition<T>>(
            sxeval::operations::Addition<T>(args));
	} else if (key == sxeval::operations::Subtraction<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Subtraction<T>::ARITY_MIN,
            sxeval::operations::Subtraction<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Subtraction<T>>(
            sxeval::operations::Subtraction<T>(args));
	} else if (key == sxeval::operations::Multiplication<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Multiplication<T>::ARITY_MIN,
            sxeval::operations::Multiplication<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Multiplication<T>>(
            sxeval::operations::Multiplication<T>(args));
	} else if (key == sxeval::operations::Division<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Division<T>::ARITY_MIN,
            sxeval::operations::Division<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Division<T>>(
            sxeval::operations::Division<T>(args));
	} else if (key == sxeval::operations::Modulo<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Modulo<T>::ARITY_MIN,
            sxeval::operations::Modulo<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Modulo<T>>(
            sxeval::operations::Modulo<T>(args));
	} else if (key == sxeval::operations::Exponentiation<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Exponentiation<T>::ARITY_MIN,
            sxeval::operations::Exponentiation<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Exponentiation<T>>(
            sxeval::operations::Exponentiation<T>(args));
	} else if (key == sxeval::operations::Equal<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Equal<T>::ARITY_MIN,
            sxeval::operations::Equal<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Equal<T>>(
            sxeval::operations::Equal<T>(args));
	} else if (key == sxeval::operations::NotEqual<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::NotEqual<T>::ARITY_MIN,
            sxeval::operations::NotEqual<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::NotEqual<T>>(
            sxeval::operations::NotEqual<T>(args));
	} else if (key == sxeval::operations::Less<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Less<T>::ARITY_MIN,
            sxeval::operations::Less<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Less<T>>(
            sxeval::operations::Less<T>(args));
	} else if (key == sxeval::operations::Greater<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Greater<T>::ARITY_MIN,
            sxeval::operations::Greater<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Greater<T>>(
            sxeval::operations::Greater<T>(args));
	} else if (key == sxeval::operations::LessOrEqual<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LessOrEqual<T>::ARITY_MIN,
            sxeval::operations::LessOrEqual<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LessOrEqual<T>>(
            sxeval::operations::LessOrEqual<T>(args));
	} else if (key == sxeval::operations::GreaterOrEqual<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::GreaterOrEqual<T>::ARITY_MIN,
            sxeval::operations::GreaterOrEqual<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::GreaterOrEqual<T>>(
            sxeval::operations::GreaterOrEqual<T>(args));
	} else if (key == sxeval::operations::LogicalAnd<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalAnd<T>::ARITY_MIN,
            sxeval::operations::LogicalAnd<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalAnd<T>>(
            sxeval::operations::LogicalAnd<T>(args));
	} else if (key == sxeval::operations::LogicalOr<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalOr<T>::ARITY_MIN,
            sxeval::operations::LogicalOr<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalOr<T>>(
            sxeval::operations::LogicalOr<T>(args));
	} else if (key == sxeval::operations::LogicalNot<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalNot<T>::ARITY_MIN,
            sxeval::operations::LogicalNot<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalNot<T>>(
            sxeval::operations::LogicalNot<T>(args));
	} else if (key == sxeval::operations::LogicalXor<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalXor<T>::ARITY_MIN,
            sxeval::operations::LogicalXor<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalXor<T>>(
            sxeval::operations::LogicalXor<T>(args));
	} else if (key == sxeval::operations::LogicalXnor<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalXnor<T>::ARITY_MIN,
            sxeval::operations::LogicalXnor<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalXnor<T>>(
            sxeval::operations::LogicalXnor<T>(args));
	} else if (key == sxeval::operations::LogicalNand<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalNand<T>::ARITY_MIN,
            sxeval::operations::LogicalNand<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalNand<T>>(
            sxeval::operations::LogicalNand<T>(args));
	} else if (key == sxeval::operations::LogicalNor<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogicalNor<T>::ARITY_MIN,
            sxeval::operations::LogicalNor<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogicalNor<T>>(
            sxeval::operations::LogicalNor<T>(args));
	} else if (key == sxeval::operations::AbsoluteValue<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::AbsoluteValue<T>::ARITY_MIN,
            sxeval::operations::AbsoluteValue<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::AbsoluteValue<T>>(
            sxeval::operations::AbsoluteValue<T>(args));
	} else if (key == sxeval::operations::Average<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Average<T>::ARITY_MIN,
            sxeval::operations::Average<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Average<T>>(
            sxeval::operations::Average<T>(args));
	} else if (key == sxeval::operations::Ceiling<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Ceiling<T>::ARITY_MIN,
            sxeval::operations::Ceiling<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Ceiling<T>>(
            sxeval::operations::Ceiling<T>(args));
	} else if (key == sxeval::operations::Clamp<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Clamp<T>::ARITY_MIN,
            sxeval::operations::Clamp<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Clamp<T>>(
            sxeval::operations::Clamp<T>(args));
	} else if (key == sxeval::operations::Expm1<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Expm1<T>::ARITY_MIN,
            sxeval::operations::Expm1<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Expm1<T>>(
            sxeval::operations::Expm1<T>(args));
	} else if (key == sxeval::operations::Floor<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Floor<T>::ARITY_MIN,
            sxeval::operations::Floor<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Floor<T>>(
            sxeval::operations::Floor<T>(args));
	} else if (key == sxeval::operations::Hypotenuse<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Hypotenuse<T>::ARITY_MIN,
            sxeval::operations::Hypotenuse<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Hypotenuse<T>>(
            sxeval::operations::Hypotenuse<T>(args));
	} else if (key == sxeval::operations::NaturalLogarithm<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::NaturalLogarithm<T>::ARITY_MIN,
            sxeval::operations::NaturalLogarithm<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::NaturalLogarithm<T>>(
            sxeval::operations::NaturalLogarithm<T>(args));
	} else if (key == sxeval::operations::Logarithm<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Logarithm<T>::ARITY_MIN,
            sxeval::operations::Logarithm<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Logarithm<T>>(
            sxeval::operations::Logarithm<T>(args));
	} else if (key == sxeval::operations::Logarithm10<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Logarithm10<T>::ARITY_MIN,
            sxeval::operations::Logarithm10<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Logarithm10<T>>(
            sxeval::operations::Logarithm10<T>(args));
	} else if (key == sxeval::operations::Logarithm1p<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Logarithm1p<T>::ARITY_MIN,
            sxeval::operations::Logarithm1p<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Logarithm1p<T>>(
            sxeval::operations::Logarithm1p<T>(args));
	} else if (key == sxeval::operations::Logarithm2<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Logarithm2<T>::ARITY_MIN,
            sxeval::operations::Logarithm2<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Logarithm2<T>>(
            sxeval::operations::Logarithm2<T>(args));
	} else if (key == sxeval::operations::LogarithmB<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::LogarithmB<T>::ARITY_MIN,
            sxeval::operations::LogarithmB<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::LogarithmB<T>>(
            sxeval::operations::LogarithmB<T>(args));
	} else if (key == sxeval::operations::Maximum<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Maximum<T>::ARITY_MIN,
            sxeval::operations::Maximum<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Maximum<T>>(
            sxeval::operations::Maximum<T>(args));
	} else if (key == sxeval::operations::Minimum<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Minimum<T>::ARITY_MIN,
            sxeval::operations::Minimum<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Minimum<T>>(
            sxeval::operations::Minimum<T>(args));
	} else if (key == sxeval::operations::Round<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Round<T>::ARITY_MIN,
            sxeval::operations::Round<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Round<T>>(
            sxeval::operations::Round<T>(args));
	} else if (key == sxeval::operations::SquareRoot<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::SquareRoot<T>::ARITY_MIN,
            sxeval::operations::SquareRoot<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::SquareRoot<T>>(
            sxeval::operations::SquareRoot<T>(args));
	} else if (key == sxeval::operations::Truncate<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Truncate<T>::ARITY_MIN,
            sxeval::operations::Truncate<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Truncate<T>>(
            sxeval::operations::Truncate<T>(args));
	} else if (key == sxeval::operations::ArcCosine<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcCosine<T>::ARITY_MIN,
            sxeval::operations::ArcCosine<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcCosine<T>>(
            sxeval::operations::ArcCosine<T>(args));
	} else if (key == sxeval::operations::ArcCosh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcCosh<T>::ARITY_MIN,
            sxeval::operations::ArcCosh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcCosh<T>>(
            sxeval::operations::ArcCosh<T>(args));
	} else if (key == sxeval::operations::ArcSine<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcSine<T>::ARITY_MIN,
            sxeval::operations::ArcSine<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcSine<T>>(
            sxeval::operations::ArcSine<T>(args));
	} else if (key == sxeval::operations::ArcSinh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcSinh<T>::ARITY_MIN,
            sxeval::operations::ArcSinh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcSinh<T>>(
            sxeval::operations::ArcSinh<T>(args));
	} else if (key == sxeval::operations::ArcTangent<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcTangent<T>::ARITY_MIN,
            sxeval::operations::ArcTangent<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcTangent<T>>(
            sxeval::operations::ArcTangent<T>(args));
	} else if (key == sxeval::operations::ArcTangent2<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcTangent2<T>::ARITY_MIN,
            sxeval::operations::ArcTangent2<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcTangent2<T>>(
            sxeval::operations::ArcTangent2<T>(args));
	} else if (key == sxeval::operations::ArcTanh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::ArcTanh<T>::ARITY_MIN,
            sxeval::operations::ArcTanh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::ArcTanh<T>>(
            sxeval::operations::ArcTanh<T>(args));
	} else if (key == sxeval::operations::Cosine<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Cosine<T>::ARITY_MIN,
            sxeval::operations::Cosine<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Cosine<T>>(
            sxeval::operations::Cosine<T>(args));
	} else if (key == sxeval::operations::Cosh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Cosh<T>::ARITY_MIN,
            sxeval::operations::Cosh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Cosh<T>>(
            sxeval::operations::Cosh<T>(args));
	} else if (key == sxeval::operations::Sine<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Sine<T>::ARITY_MIN,
            sxeval::operations::Sine<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Sine<T>>(
            sxeval::operations::Sine<T>(args));
	} else if (key == sxeval::operations::Sinh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Sinh<T>::ARITY_MIN,
            sxeval::operations::Sinh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Sinh<T>>(
            sxeval::operations::Sinh<T>(args));
	} else if (key == sxeval::operations::Tangent<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Tangent<T>::ARITY_MIN,
            sxeval::operations::Tangent<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Tangent<T>>(
            sxeval::operations::Tangent<T>(args));
	} else if (key == sxeval::operations::Tanh<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::Tanh<T>::ARITY_MIN,
            sxeval::operations::Tanh<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::Tanh<T>>(
            sxeval::operations::Tanh<T>(args));
	} else if (key == sxeval::operations::DegreesToRadians<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::DegreesToRadians<T>::ARITY_MIN,
            sxeval::operations::DegreesToRadians<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::DegreesToRadians<T>>(
            sxeval::operations::DegreesToRadians<T>(args));
	} else if (key == sxeval::operations::RadiansToDegrees<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::RadiansToDegrees<T>::ARITY_MIN,
            sxeval::operations::RadiansToDegrees<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::RadiansToDegrees<T>>(
            sxeval::operations::RadiansToDegrees<T>(args));
	} else if (key == sxeval::operations::DegreesToGradians<T>::KEY) {
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::DegreesToGradians<T>::ARITY_MIN,
            sxeval::operations::DegreesToGradians<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::DegreesToGradians<T>>(
            sxeval::operations::DegreesToGradians<T>(args));
	}
    throw std::invalid_argument("Unknown operation key: " + key);
}

template <typename T>
void sxeval::operations::Operations<T>::checkArity(const std::string& key,
    int nArgs, int arityMin, int arityMax)
{
    if (nArgs < arityMin) {
        throw std::invalid_argument("Operation " + key + " requires at least "
            + std::to_string(arityMin) + " arguments");
    }
    if (arityMax != UNLIMITED_ARITY && nArgs > arityMax) {
        throw std::invalid_argument("Operation " + key + " requires at most "
            + std::to_string(arityMax) + " arguments");
    }
}

#endif /* SXEVAL_OPERATIONS_HPP */
