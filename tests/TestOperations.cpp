
#include <catch2/catch_test_macros.hpp>
#include <sxeval/operations/OperationsFactory.hpp>
#include <sxeval/AInstruction.hpp>
#include <sxeval/Value.hpp>
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
    operations::OperationsFactory<int> factory;

    AInstruction<int>* instr = dynamic_cast<AInstruction<int>*>(
        new Value<int>(0));
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
        factory.create("+", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Subtraction<int>*>(
        factory.create("-", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Multiplication<int>*>(
        factory.create("*", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Division<int>*>(
        factory.create("/", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Modulo<int>*>(
        factory.create("%", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Exponentiation<int>*>(
        factory.create("^", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Equal<int>*>(
        factory.create("=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::NotEqual<int>*>(
        factory.create("!=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Less<int>*>(
        factory.create("<", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Greater<int>*>(
        factory.create(">", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LessOrEqual<int>*>(
        factory.create("<=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::GreaterOrEqual<int>*>(
        factory.create(">=", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalAnd<int>*>(
        factory.create("and", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalOr<int>*>(
        factory.create("or", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNot<int>*>(
        factory.create("not", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalXor<int>*>(
        factory.create("xor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalXnor<int>*>(
        factory.create("xnor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNand<int>*>(
        factory.create("nand", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogicalNor<int>*>(
        factory.create("nor", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::AbsoluteValue<int>*>(
        factory.create("abs", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Average<int>*>(
        factory.create("avg", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Ceiling<int>*>(
        factory.create("ceil", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Clamp<int>*>(
        factory.create("clamp", args3).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Expm1<int>*>(
        factory.create("expm1", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Floor<int>*>(
        factory.create("floor", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Hypotenuse<int>*>(
        factory.create("hypot", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::NaturalLogarithm<int>*>(
        factory.create("ln", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm<int>*>(
        factory.create("log", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm10<int>*>(
        factory.create("log10", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm1p<int>*>(
        factory.create("log1p", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Logarithm2<int>*>(
        factory.create("log2", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::LogarithmB<int>*>(
        factory.create("logB", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Maximum<int>*>(
        factory.create("max", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Minimum<int>*>(
        factory.create("min", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Round<int>*>(
        factory.create("round", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::SquareRoot<int>*>(
        factory.create("sqrt", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Truncate<int>*>(
        factory.create("trunc", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcCosine<int>*>(
        factory.create("acos", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcCosh<int>*>(
        factory.create("acosh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcSine<int>*>(
        factory.create("asin", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcSinh<int>*>(
        factory.create("asinh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTangent<int>*>(
        factory.create("atan", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTangent2<int>*>(
        factory.create("atan2", args2).get()));
    REQUIRE(nullptr != dynamic_cast<operations::ArcTanh<int>*>(
        factory.create("atanh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Cosine<int>*>(
        factory.create("cos", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Cosh<int>*>(
        factory.create("cosh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Sine<int>*>(
        factory.create("sin", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Sinh<int>*>(
        factory.create("sinh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Tangent<int>*>(
        factory.create("tan", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::Tanh<int>*>(
        factory.create("tanh", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::DegreesToRadians<int>*>(
        factory.create("deg2rad", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::RadiansToDegrees<int>*>(
        factory.create("rad2deg", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::DegreesToGradians<int>*>(
        factory.create("deg2grad", args1).get()));
    REQUIRE(nullptr != dynamic_cast<operations::GradiansToDegrees<int>*>(
        factory.create("grad2deg", args1).get()));

    delete instr;
}

TEST_CASE("Mathematical tests", "[operations]") {

    operations::OperationsFactory<int> factory_int;
    operations::OperationsFactory<signed char> factory_signed_char;
    operations::OperationsFactory<short int> factory_short_int;
    operations::OperationsFactory<long int> factory_long_int;
    operations::OperationsFactory<unsigned int> factory_unsigned_int;
    operations::OperationsFactory<unsigned char> factory_unsigned_char;
    operations::OperationsFactory<unsigned long int> factory_unsigned_long_int;
    operations::OperationsFactory<float> factory_float;
    operations::OperationsFactory<double> factory_double;
    operations::OperationsFactory<long double> factory_long_double;

    SECTION("Addition") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("+", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 10};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("+", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("+", args);
        op->execute();
        REQUIRE(3000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("+", args);
        op->execute();
        REQUIRE(300000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("+", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 27};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("+", args);
        op->execute();
        REQUIRE(127 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("+", args);
        op->execute();
        REQUIRE(700000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("+", args);
        op->execute();
        REQUIRE(3.2f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 2.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("+", args);
        op->execute();
        REQUIRE(3.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 2.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("+", args);
        op->execute();
        REQUIRE(3.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Subtraction") {
        {
        int rawArgs[2] = {5, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("-", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {10, 5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("-", args);
        op->execute();
        REQUIRE(5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("-", args);
        op->execute();
        REQUIRE(1000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("-", args);
        op->execute();
        REQUIRE(200000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 3};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("-", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("-", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("-", args);
        op->execute();
        REQUIRE(700000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.5f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("-", args);
        op->execute();
        REQUIRE(3.3f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.5, 0.3};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("-", args);
        op->execute();
        REQUIRE(0.2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {3.0L, 2.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("-", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Multiplication") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("*", args);
        op->execute();
        REQUIRE(6 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 10};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("*", args);
        op->execute();
        REQUIRE(-50 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {10, 2};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("*", args);
        op->execute();
        REQUIRE(20 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {10, 200};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("*", args);
        op->execute();
        REQUIRE(2000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("*", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {10, 2};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("*", args);
        op->execute();
        REQUIRE(20 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {100, 200};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("*", args);
        op->execute();
        REQUIRE(20000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("*", args);
        op->execute();
        REQUIRE(2.42f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {10.0, 2.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("*", args);
        op->execute();
        REQUIRE(20.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("*", args);
        op->execute();
        REQUIRE(0.00000002L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Division") {
        {
        int rawArgs[2] = {6, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("/", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-50, 10};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("/", args);
        op->execute();
        REQUIRE(-5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("/", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("/", args);
        op->execute();
        REQUIRE(3 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("/", args);
        op->execute();
        REQUIRE(2 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("/", args);
        op->execute();
        REQUIRE(4 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("/", args);
        op->execute();
        REQUIRE(8 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.5f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("/", args);
        op->execute();
        REQUIRE(2.5f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {2.0, 0.5};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("/", args);
        op->execute();
        REQUIRE(4.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {2.0L, 0.5L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("/", args);
        op->execute();
        REQUIRE(4.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Modulo") {
        {
        int rawArgs[2] = {5, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("%", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-50, 10};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {300000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {5, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("%", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 27};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("%", args);
        op->execute();
        REQUIRE(19 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {800000, 100000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("%", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {5.0f, 2.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("%", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {5.0, 2.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("%", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {3.0L, 2.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("%", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Exponentiation") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("^", args);
        op->execute();
        REQUIRE(8 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, 2};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("^", args);
        op->execute();
        REQUIRE(25 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {10, 2};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("^", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100, 2};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("^", args);
        op->execute();
        REQUIRE(10000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("^", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {10, 2};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("^", args);
        op->execute();
        REQUIRE(100 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {100, 2};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("^", args);
        op->execute();
        REQUIRE(10000 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {10.0f, 2.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("^", args);
        op->execute();
        REQUIRE(100.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {10.0, 2.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("^", args);
        op->execute();
        REQUIRE(100.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {10.0L, 2.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("^", args);
        op->execute();
        REQUIRE(100.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Equal") {
        {
        int rawArgs[2] = {2, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 100};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 300000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 1.1f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.1};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0001L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("NotEqual") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -6};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 27};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("!=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Less") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("<", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("<", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("Greater") {
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create(">", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create(">", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LessOrEqual") {
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("<=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("<=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("GreaterOrEqual") {
        {
        int rawArgs[2] = {3, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {2, 3};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-4, -5};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {-5, -4};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {2000, 1000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1000, 2000};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {200000, 100000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {100000, 200000};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {2, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {127, 100};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {100, 127};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {400000, 300000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {300000, 400000};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {2.2f, 1.1f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.1f, 2.2f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.2, 0.1};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.1, 0.2};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0002L, 0.0001L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create(">=", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0001L, 0.0002L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create(">=", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalAnd") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("and", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("and", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("and", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("and", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("and", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("and", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("and", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("and", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalOr") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("or", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("or", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("or", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("or", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("or", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("or", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("or", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("or", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNot") {
        {
        int rawArgs[1] = {1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = factory_int.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        int rawArgs[1] = {0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = factory_int.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = factory_signed_char.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = factory_signed_char.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = factory_short_int.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = factory_short_int.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = factory_long_int.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = factory_long_int.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned int rawArgs[1] = {1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        std::vector<AInstruction<unsigned int>*> args = {instr0};
        auto op = factory_unsigned_int.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned int rawArgs[1] = {0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        std::vector<AInstruction<unsigned int>*> args = {instr0};
        auto op = factory_unsigned_int.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned char rawArgs[1] = {1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        std::vector<AInstruction<unsigned char>*> args = {instr0};
        auto op = factory_unsigned_char.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned char rawArgs[1] = {0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        std::vector<AInstruction<unsigned char>*> args = {instr0};
        auto op = factory_unsigned_char.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        unsigned long int rawArgs[1] = {1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0};
        auto op = factory_unsigned_long_int.create("not", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        }
        {
        unsigned long int rawArgs[1] = {0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0};
        auto op = factory_unsigned_long_int.create("not", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = factory_float.create("not", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = factory_float.create("not", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = factory_double.create("not", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = factory_double.create("not", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = factory_long_double.create("not", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = factory_long_double.create("not", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        }
    }
    SECTION("LogicalXor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalXnor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xnor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("xnor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xnor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xnor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xnor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("xnor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xnor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xnor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xnor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("xnor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xnor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xnor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xnor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("xnor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNand") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nand", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nand", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nand", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nand", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nand", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nand", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nand", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nand", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("LogicalNor") {
        {
        int rawArgs[2] = {1, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {1, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        int rawArgs[2] = {0, 0};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {0, 0};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {0, 0};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {0, 0};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 1};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {0, 0};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 1};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {0, 0};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 1};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nor", args);
        op->execute();
        REQUIRE(0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {0, 0};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("nor", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nor", args);
        op->execute();
        REQUIRE(0.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {0.0f, 0.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("nor", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nor", args);
        op->execute();
        REQUIRE(0.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {0.0, 0.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("nor", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nor", args);
        op->execute();
        REQUIRE(0.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {0.0L, 0.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("nor", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }
    SECTION("AbsoluteValue") {
        {
        int rawArgs[1] = {-1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = factory_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        int rawArgs[1] = {1};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        std::vector<AInstruction<int>*> args = {instr0};
        auto op = factory_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {-1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = factory_signed_char.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        signed char rawArgs[1] = {1};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        std::vector<AInstruction<signed char>*> args = {instr0};
        auto op = factory_signed_char.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {-1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = factory_short_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        short int rawArgs[1] = {1};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        std::vector<AInstruction<short int>*> args = {instr0};
        auto op = factory_short_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {-1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = factory_long_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        long int rawArgs[1] = {1};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        std::vector<AInstruction<long int>*> args = {instr0};
        auto op = factory_long_int.create("abs", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {-1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = factory_float.create("abs", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        float rawArgs[1] = {1.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        std::vector<AInstruction<float>*> args = {instr0};
        auto op = factory_float.create("abs", args);
        op->execute();
        REQUIRE(1.0f == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {-1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = factory_double.create("abs", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        double rawArgs[1] = {1.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        std::vector<AInstruction<double>*> args = {instr0};
        auto op = factory_double.create("abs", args);
        op->execute();
        REQUIRE(1.0 == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {-1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = factory_long_double.create("abs", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
        {
        long double rawArgs[1] = {1.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        std::vector<AInstruction<long double>*> args = {instr0};
        auto op = factory_long_double.create("abs", args);
        op->execute();
        REQUIRE(1.0L == op->getResult());
        delete instr0;
        }
    }
    SECTION("Average") {
        {
        int rawArgs[2] = {1, 2};
        AInstruction<int>* instr0 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[0]));
        AInstruction<int>* instr1 = dynamic_cast<AInstruction<int>*>(
        new Value<int>(rawArgs[1]));
        std::vector<AInstruction<int>*> args = {instr0, instr1};
        auto op = factory_int.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        signed char rawArgs[2] = {1, 2};
        AInstruction<signed char>* instr0 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[0]));
        AInstruction<signed char>* instr1 = dynamic_cast<AInstruction<signed char>*>(
        new Value<signed char>(rawArgs[1]));
        std::vector<AInstruction<signed char>*> args = {instr0, instr1};
        auto op = factory_signed_char.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        short int rawArgs[2] = {1, 2};
        AInstruction<short int>* instr0 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[0]));
        AInstruction<short int>* instr1 = dynamic_cast<AInstruction<short int>*>(
        new Value<short int>(rawArgs[1]));
        std::vector<AInstruction<short int>*> args = {instr0, instr1};
        auto op = factory_short_int.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long int rawArgs[2] = {1, 2};
        AInstruction<long int>* instr0 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[0]));
        AInstruction<long int>* instr1 = dynamic_cast<AInstruction<long int>*>(
        new Value<long int>(rawArgs[1]));
        std::vector<AInstruction<long int>*> args = {instr0, instr1};
        auto op = factory_long_int.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned int rawArgs[2] = {1, 2};
        AInstruction<unsigned int>* instr0 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[0]));
        AInstruction<unsigned int>* instr1 = dynamic_cast<AInstruction<unsigned int>*>(
        new Value<unsigned int>(rawArgs[1]));
        std::vector<AInstruction<unsigned int>*> args = {instr0, instr1};
        auto op = factory_unsigned_int.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned char rawArgs[2] = {1, 2};
        AInstruction<unsigned char>* instr0 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[0]));
        AInstruction<unsigned char>* instr1 = dynamic_cast<AInstruction<unsigned char>*>(
        new Value<unsigned char>(rawArgs[1]));
        std::vector<AInstruction<unsigned char>*> args = {instr0, instr1};
        auto op = factory_unsigned_char.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        unsigned long int rawArgs[2] = {1, 2};
        AInstruction<unsigned long int>* instr0 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[0]));
        AInstruction<unsigned long int>* instr1 = dynamic_cast<AInstruction<unsigned long int>*>(
        new Value<unsigned long int>(rawArgs[1]));
        std::vector<AInstruction<unsigned long int>*> args = {instr0, instr1};
        auto op = factory_unsigned_long_int.create("avg", args);
        op->execute();
        REQUIRE(1 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        float rawArgs[2] = {1.0f, 2.0f};
        AInstruction<float>* instr0 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[0]));
        AInstruction<float>* instr1 = dynamic_cast<AInstruction<float>*>(
        new Value<float>(rawArgs[1]));
        std::vector<AInstruction<float>*> args = {instr0, instr1};
        auto op = factory_float.create("avg", args);
        op->execute();
        REQUIRE(1.5f == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        double rawArgs[2] = {1.0, 2.0};
        AInstruction<double>* instr0 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[0]));
        AInstruction<double>* instr1 = dynamic_cast<AInstruction<double>*>(
        new Value<double>(rawArgs[1]));
        std::vector<AInstruction<double>*> args = {instr0, instr1};
        auto op = factory_double.create("avg", args);
        op->execute();
        REQUIRE(1.5 == op->getResult());
        delete instr0;
        delete instr1;
        }
        {
        long double rawArgs[2] = {1.0L, 2.0L};
        AInstruction<long double>* instr0 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[0]));
        AInstruction<long double>* instr1 = dynamic_cast<AInstruction<long double>*>(
        new Value<long double>(rawArgs[1]));
        std::vector<AInstruction<long double>*> args = {instr0, instr1};
        auto op = factory_long_double.create("avg", args);
        op->execute();
        REQUIRE(1.5L == op->getResult());
        delete instr0;
        delete instr1;
        }
    }

}

