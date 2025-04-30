
#include <catch2/catch_test_macros.hpp>
#include <sxeval/operations/Operations.hpp>
#include <sxeval/AInstruction.hpp>
#include <sxeval/operations/Addition.hpp>
#include <sxeval/operations/Subtraction.hpp>
#include <sxeval/operations/Multiplication.hpp>
#include <sxeval/operations/Division.hpp>
#include <sxeval/operations/Modulo.hpp>
#include <sxeval/operations/Exponentiation.hpp>
#include <sxeval/operations/Equal.hpp>
#include <sxeval/operations/NotEqual.hpp>
#include <sxeval/operations/Less.hpp>
#include <sxeval/operations/Greater.hpp>
#include <sxeval/operations/LessOrEqual.hpp>
#include <sxeval/operations/GreaterOrEqual.hpp>
#include <sxeval/operations/LogicalAnd.hpp>
#include <sxeval/operations/LogicalOr.hpp>
#include <sxeval/operations/LogicalNot.hpp>
#include <sxeval/operations/LogicalXor.hpp>
#include <sxeval/operations/LogicalXnor.hpp>
#include <sxeval/operations/LogicalNand.hpp>
#include <sxeval/operations/LogicalNor.hpp>
#include <sxeval/operations/AbsoluteValue.hpp>
#include <sxeval/operations/Average.hpp>
#include <sxeval/operations/Ceiling.hpp>
#include <sxeval/operations/Clamp.hpp>
#include <sxeval/operations/Expm1.hpp>
#include <sxeval/operations/Floor.hpp>
#include <sxeval/operations/Hypotenuse.hpp>
#include <sxeval/operations/NaturalLogarithm.hpp>
#include <sxeval/operations/Logarithm.hpp>
#include <sxeval/operations/Logarithm10.hpp>
#include <sxeval/operations/Logarithm1p.hpp>
#include <sxeval/operations/Logarithm2.hpp>
#include <sxeval/operations/LogarithmB.hpp>
#include <sxeval/operations/Maximum.hpp>
#include <sxeval/operations/Minimum.hpp>
#include <sxeval/operations/Round.hpp>
#include <sxeval/operations/SquareRoot.hpp>
#include <sxeval/operations/Truncate.hpp>
#include <sxeval/operations/ArcCosine.hpp>
#include <sxeval/operations/ArcCosh.hpp>
#include <sxeval/operations/ArcSine.hpp>
#include <sxeval/operations/ArcSinh.hpp>
#include <sxeval/operations/ArcTangent.hpp>
#include <sxeval/operations/ArcTangent2.hpp>
#include <sxeval/operations/ArcTanh.hpp>
#include <sxeval/operations/Cosine.hpp>
#include <sxeval/operations/Cosh.hpp>
#include <sxeval/operations/Sine.hpp>
#include <sxeval/operations/Sinh.hpp>
#include <sxeval/operations/Tangent.hpp>
#include <sxeval/operations/Tanh.hpp>
#include <sxeval/operations/DegreesToRadians.hpp>
#include <sxeval/operations/RadiansToDegrees.hpp>
#include <sxeval/operations/DegreesToGradians.hpp>
#include <sxeval/operations/GradiansToDegrees.hpp>

using namespace sxeval;

TEST_CASE("Operations instanciation", "[operations]") {
    int argInt = 0;
    AInstruction<int>* instr = new AInstruction<int>(argInt);
    std::vector<AInstruction<int>*> args1;
    args1.push_back(instr);
    std::vector<AInstruction<int>*> args2;
    args2.push_back(instr);
    args2.push_back(instr);
    std::vector<AInstruction<int>*> args3;
    args3.push_back(instr);
    args3.push_back(instr);
    args3.push_back(instr);

    REQUIRE(dynamic_cast<operations::Addition<int>*>(
        operations::Operations<int>::create("+", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Subtraction<int>*>(
        operations::Operations<int>::create("-", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Multiplication<int>*>(
        operations::Operations<int>::create("*", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Division<int>*>(
        operations::Operations<int>::create("/", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Modulo<int>*>(
        operations::Operations<int>::create("%", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Exponentiation<int>*>(
        operations::Operations<int>::create("^", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Equal<int>*>(
        operations::Operations<int>::create("=", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::NotEqual<int>*>(
        operations::Operations<int>::create("!=", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Less<int>*>(
        operations::Operations<int>::create("<", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Greater<int>*>(
        operations::Operations<int>::create(">", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LessOrEqual<int>*>(
        operations::Operations<int>::create("<=", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::GreaterOrEqual<int>*>(
        operations::Operations<int>::create(">=", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalAnd<int>*>(
        operations::Operations<int>::create("and", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalOr<int>*>(
        operations::Operations<int>::create("or", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalNot<int>*>(
        operations::Operations<int>::create("not", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalXor<int>*>(
        operations::Operations<int>::create("xor", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalXnor<int>*>(
        operations::Operations<int>::create("xnor", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalNand<int>*>(
        operations::Operations<int>::create("nand", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogicalNor<int>*>(
        operations::Operations<int>::create("nor", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::AbsoluteValue<int>*>(
        operations::Operations<int>::create("abs", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Average<int>*>(
        operations::Operations<int>::create("avg", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Ceiling<int>*>(
        operations::Operations<int>::create("ceil", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Clamp<int>*>(
        operations::Operations<int>::create("clamp", args3).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Expm1<int>*>(
        operations::Operations<int>::create("expm1", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Floor<int>*>(
        operations::Operations<int>::create("floor", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Hypotenuse<int>*>(
        operations::Operations<int>::create("hypot", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::NaturalLogarithm<int>*>(
        operations::Operations<int>::create("ln", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Logarithm<int>*>(
        operations::Operations<int>::create("log", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Logarithm10<int>*>(
        operations::Operations<int>::create("log10", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Logarithm1p<int>*>(
        operations::Operations<int>::create("log1p", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Logarithm2<int>*>(
        operations::Operations<int>::create("log2", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::LogarithmB<int>*>(
        operations::Operations<int>::create("logB", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Maximum<int>*>(
        operations::Operations<int>::create("max", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Minimum<int>*>(
        operations::Operations<int>::create("min", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Round<int>*>(
        operations::Operations<int>::create("round", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::SquareRoot<int>*>(
        operations::Operations<int>::create("sqrt", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Truncate<int>*>(
        operations::Operations<int>::create("trunc", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcCosine<int>*>(
        operations::Operations<int>::create("acos", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcCosh<int>*>(
        operations::Operations<int>::create("acosh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcSine<int>*>(
        operations::Operations<int>::create("asin", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcSinh<int>*>(
        operations::Operations<int>::create("asinh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcTangent<int>*>(
        operations::Operations<int>::create("atan", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcTangent2<int>*>(
        operations::Operations<int>::create("atan2", args2).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::ArcTanh<int>*>(
        operations::Operations<int>::create("atanh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Cosine<int>*>(
        operations::Operations<int>::create("cos", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Cosh<int>*>(
        operations::Operations<int>::create("cosh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Sine<int>*>(
        operations::Operations<int>::create("sin", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Sinh<int>*>(
        operations::Operations<int>::create("sinh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Tangent<int>*>(
        operations::Operations<int>::create("tan", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::Tanh<int>*>(
        operations::Operations<int>::create("tanh", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::DegreesToRadians<int>*>(
        operations::Operations<int>::create("deg2rad", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::RadiansToDegrees<int>*>(
        operations::Operations<int>::create("rad2deg", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::DegreesToGradians<int>*>(
        operations::Operations<int>::create("deg2grad", args1).get()) != nullptr);
    REQUIRE(dynamic_cast<operations::GradiansToDegrees<int>*>(
        operations::Operations<int>::create("grad2deg", args1).get()) != nullptr);
    
    delete instr;
}
