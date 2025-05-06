
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

    REQUIRE(nullptr != dynamic_cast<operations::Addition<int>*>(
        operations::Operations<int>::create("+", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Subtraction<int>*>(
        operations::Operations<int>::create("-", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Multiplication<int>*>(
        operations::Operations<int>::create("*", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Division<int>*>(
        operations::Operations<int>::create("/", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Modulo<int>*>(
        operations::Operations<int>::create("%", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Exponentiation<int>*>(
        operations::Operations<int>::create("^", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Equal<int>*>(
        operations::Operations<int>::create("=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::NotEqual<int>*>(
        operations::Operations<int>::create("!=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Less<int>*>(
        operations::Operations<int>::create("<", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Greater<int>*>(
        operations::Operations<int>::create(">", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LessOrEqual<int>*>(
        operations::Operations<int>::create("<=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::GreaterOrEqual<int>*>(
        operations::Operations<int>::create(">=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalAnd<int>*>(
        operations::Operations<int>::create("and", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalOr<int>*>(
        operations::Operations<int>::create("or", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNot<int>*>(
        operations::Operations<int>::create("not", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalXor<int>*>(
        operations::Operations<int>::create("xor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalXnor<int>*>(
        operations::Operations<int>::create("xnor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNand<int>*>(
        operations::Operations<int>::create("nand", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNor<int>*>(
        operations::Operations<int>::create("nor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::AbsoluteValue<int>*>(
        operations::Operations<int>::create("abs", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Average<int>*>(
        operations::Operations<int>::create("avg", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Ceiling<int>*>(
        operations::Operations<int>::create("ceil", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Clamp<int>*>(
        operations::Operations<int>::create("clamp", args3).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Expm1<int>*>(
        operations::Operations<int>::create("expm1", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Floor<int>*>(
        operations::Operations<int>::create("floor", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Hypotenuse<int>*>(
        operations::Operations<int>::create("hypot", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::NaturalLogarithm<int>*>(
        operations::Operations<int>::create("ln", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm<int>*>(
        operations::Operations<int>::create("log", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm10<int>*>(
        operations::Operations<int>::create("log10", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm1p<int>*>(
        operations::Operations<int>::create("log1p", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm2<int>*>(
        operations::Operations<int>::create("log2", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogarithmB<int>*>(
        operations::Operations<int>::create("logB", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Maximum<int>*>(
        operations::Operations<int>::create("max", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Minimum<int>*>(
        operations::Operations<int>::create("min", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Round<int>*>(
        operations::Operations<int>::create("round", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::SquareRoot<int>*>(
        operations::Operations<int>::create("sqrt", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Truncate<int>*>(
        operations::Operations<int>::create("trunc", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcCosine<int>*>(
        operations::Operations<int>::create("acos", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcCosh<int>*>(
        operations::Operations<int>::create("acosh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcSine<int>*>(
        operations::Operations<int>::create("asin", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcSinh<int>*>(
        operations::Operations<int>::create("asinh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTangent<int>*>(
        operations::Operations<int>::create("atan", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTangent2<int>*>(
        operations::Operations<int>::create("atan2", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTanh<int>*>(
        operations::Operations<int>::create("atanh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Cosine<int>*>(
        operations::Operations<int>::create("cos", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Cosh<int>*>(
        operations::Operations<int>::create("cosh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Sine<int>*>(
        operations::Operations<int>::create("sin", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Sinh<int>*>(
        operations::Operations<int>::create("sinh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Tangent<int>*>(
        operations::Operations<int>::create("tan", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Tanh<int>*>(
        operations::Operations<int>::create("tanh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::DegreesToRadians<int>*>(
        operations::Operations<int>::create("deg2rad", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::RadiansToDegrees<int>*>(
        operations::Operations<int>::create("rad2deg", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::DegreesToGradians<int>*>(
        operations::Operations<int>::create("deg2grad", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::GradiansToDegrees<int>*>(
        operations::Operations<int>::create("grad2deg", args1).get()));

    delete instr;
}

TEST_CASE("Mathematical tests", "[operations]") {

    SECTION("Addition") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("+", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 10};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("+", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("+", args);
        op->execute();
        REQUIRE(3000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("+", args);
        op->execute();
        REQUIRE(300000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("+", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 27};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("+", args);
        op->execute();
        REQUIRE(127 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("+", args);
        op->execute();
        REQUIRE(700000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("+", args);
        op->execute();
        REQUIRE(3.2f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 2.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("+", args);
        op->execute();
        REQUIRE(3.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 2.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("+", args);
        op->execute();
        REQUIRE(3.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Subtraction") {
        {
        int rawArgs[2] = {5, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("-", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {10, 5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("-", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("-", args);
        op->execute();
        REQUIRE(1000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("-", args);
        op->execute();
        REQUIRE(200000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 3};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("-", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("-", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("-", args);
        op->execute();
        REQUIRE(700000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.5f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("-", args);
        op->execute();
        REQUIRE(3.3f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.5, 0.3};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("-", args);
        op->execute();
        REQUIRE(0.2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {3.0L, 2.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("-", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Multiplication") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("*", args);
        op->execute();
        REQUIRE(6 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 10};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("*", args);
        op->execute();
        REQUIRE(-50 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {10, 2};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("*", args);
        op->execute();
        REQUIRE(20 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("*", args);
        op->execute();
        REQUIRE(20000000000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("*", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {10, 2};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("*", args);
        op->execute();
        REQUIRE(20 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("*", args);
        op->execute();
        REQUIRE(120000000000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("*", args);
        op->execute();
        REQUIRE(2.42f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {10.0, 2.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("*", args);
        op->execute();
        REQUIRE(20.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("*", args);
        op->execute();
        REQUIRE(0.00000002L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Division") {
        {
        int rawArgs[2] = {6, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("/", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-50, 10};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("/", args);
        op->execute();
        REQUIRE(-5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("/", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("/", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("/", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("/", args);
        op->execute();
        REQUIRE(4 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("/", args);
        op->execute();
        REQUIRE(8 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.5f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("/", args);
        op->execute();
        REQUIRE(2.5f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {2.0, 0.5};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("/", args);
        op->execute();
        REQUIRE(4.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {2.0L, 0.5L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("/", args);
        op->execute();
        REQUIRE(4.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Modulo") {
        {
        int rawArgs[2] = {5, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("%", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-50, 10};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("%", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("%", args);
        op->execute();
        REQUIRE(19 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.0f, 2.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("%", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {5.0, 2.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("%", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {3.0L, 2.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("%", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Exponentiation") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("^", args);
        op->execute();
        REQUIRE(8 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 2};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("^", args);
        op->execute();
        REQUIRE(25 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {10, 2};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("^", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 2};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("^", args);
        op->execute();
        REQUIRE(10000000000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("^", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {10, 2};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("^", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 2};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("^", args);
        op->execute();
        REQUIRE(90000000000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {10.0f, 2.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("^", args);
        op->execute();
        REQUIRE(100.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {10.0, 2.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("^", args);
        op->execute();
        REQUIRE(100.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {10.0L, 2.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("^", args);
        op->execute();
        REQUIRE(100.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Equal") {
        {
        int rawArgs[2] = {2, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 100};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 300000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 1.1f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.1};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0001L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("NotEqual") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -6};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 27};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Less") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Greater") {
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LessOrEqual") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("GreaterOrEqual") {
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalAnd") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("and", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("and", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("and", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalOr") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("or", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("or", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("or", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNot") {
        {
        int rawArgs[1] = {1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = operations::Operations<int>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        int rawArgs[1] = {0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = operations::Operations<int>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = operations::Operations<signed char>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = operations::Operations<signed char>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = operations::Operations<short int>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = operations::Operations<short int>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = operations::Operations<long int>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = operations::Operations<long int>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned int rawArgs[1] = {1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        std::vector<AInstruction<unsigned int>*> args = {instr0};
        auto op = operations::Operations<unsigned int>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned int rawArgs[1] = {0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        std::vector<AInstruction<unsigned int>*> args = {instr0};
        auto op = operations::Operations<unsigned int>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned char rawArgs[1] = {1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        std::vector<AInstruction<unsigned char>*> args = {instr0};
        auto op = operations::Operations<unsigned char>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned char rawArgs[1] = {0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        std::vector<AInstruction<unsigned char>*> args = {instr0};
        auto op = operations::Operations<unsigned char>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned long int rawArgs[1] = {1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0};
        auto op = operations::Operations<unsigned long int>::create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned long int rawArgs[1] = {0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0};
        auto op = operations::Operations<unsigned long int>::create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = operations::Operations<float>::create("not", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = operations::Operations<float>::create("not", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = operations::Operations<double>::create("not", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = operations::Operations<double>::create("not", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = operations::Operations<long double>::create("not", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = operations::Operations<long double>::create("not", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        }
    }
    SECTION("LogicalXor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalXnor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xnor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xnor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xnor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("xnor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xnor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xnor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xnor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("xnor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xnor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xnor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xnor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("xnor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNand") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nand", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nand", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nand", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("nor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("nor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("nor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("AbsoluteValue") {
        {
        int rawArgs[1] = {-1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = operations::Operations<int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        int rawArgs[1] = {1};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = operations::Operations<int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {-1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = operations::Operations<signed char>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {1};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = operations::Operations<signed char>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {-1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = operations::Operations<short int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {1};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = operations::Operations<short int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {-1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = operations::Operations<long int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {1};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = operations::Operations<long int>::create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {-1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = operations::Operations<float>::create("abs", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {1.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = operations::Operations<float>::create("abs", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {-1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = operations::Operations<double>::create("abs", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {1.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = operations::Operations<double>::create("abs", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {-1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = operations::Operations<long double>::create("abs", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {1.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = operations::Operations<long double>::create("abs", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
    }
    SECTION("Average") {
        {
        int rawArgs[2] = {1, 2};
        AInstruction<int>* instr0 = new AInstruction<int>(rawArgs[0]);
        AInstruction<int>* instr1 = new AInstruction<int>(rawArgs[1]);
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = operations::Operations<int>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 2};
        AInstruction<signed char>* instr0 = new AInstruction<signed char>(rawArgs[0]);
        AInstruction<signed char>* instr1 = new AInstruction<signed char>(rawArgs[1]);
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = operations::Operations<signed char>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 2};
        AInstruction<short int>* instr0 = new AInstruction<short int>(rawArgs[0]);
        AInstruction<short int>* instr1 = new AInstruction<short int>(rawArgs[1]);
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = operations::Operations<short int>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 2};
        AInstruction<long int>* instr0 = new AInstruction<long int>(rawArgs[0]);
        AInstruction<long int>* instr1 = new AInstruction<long int>(rawArgs[1]);
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = operations::Operations<long int>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = new AInstruction<unsigned int>(rawArgs[0]);
        AInstruction<unsigned int>* instr1 = new AInstruction<unsigned int>(rawArgs[1]);
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned int>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 2};
        AInstruction<unsigned char>* instr0 = new AInstruction<unsigned char>(rawArgs[0]);
        AInstruction<unsigned char>* instr1 = new AInstruction<unsigned char>(rawArgs[1]);
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned char>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 2};
        AInstruction<unsigned long int>* instr0 = new AInstruction<unsigned long int>(rawArgs[0]);
        AInstruction<unsigned long int>* instr1 = new AInstruction<unsigned long int>(rawArgs[1]);
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = operations::Operations<unsigned long int>::create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 2.0f};
        AInstruction<float>* instr0 = new AInstruction<float>(rawArgs[0]);
        AInstruction<float>* instr1 = new AInstruction<float>(rawArgs[1]);
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = operations::Operations<float>::create("avg", args);
        op->execute();
        REQUIRE(1.5f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 2.0};
        AInstruction<double>* instr0 = new AInstruction<double>(rawArgs[0]);
        AInstruction<double>* instr1 = new AInstruction<double>(rawArgs[1]);
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = operations::Operations<double>::create("avg", args);
        op->execute();
        REQUIRE(1.5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 2.0L};
        AInstruction<long double>* instr0 = new AInstruction<long double>(rawArgs[0]);
        AInstruction<long double>* instr1 = new AInstruction<long double>(rawArgs[1]);
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = operations::Operations<long double>::create("avg", args);
        op->execute();
        REQUIRE(1.5L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }

}

