#include "myVar.hpp"
#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        std::cerr << "Example: " << argv[0] << " '(+ x 3.4 -4.1 y a b)'" << std::endl;
        return 1;
    }

    /* variables */
    double x = 0.0, y = 0.0;

    /* encapsulated variables */
    MyVar a, b;
    a.setValue(0);
    b.setValue(0);

    /* resolveVariable function */
    auto resolveVariable = [&](const std::string& var) -> double& {
        if (var == "x") {
            return x;
        } else if (var == "y") {
            return y;
        }
        throw std::invalid_argument("Unknown variable");
    };

    /* resolveEncapsulated function */
    auto resolveEncapsulated = [&](const std::string& var)
        -> std::function<double(void)>
    {
        if (var == "a") {
            return [&]() { return a.getValue(); };
        } else if (var == "b") {
            return [&]() { return b.getValue(); };
        }
        throw std::invalid_argument("Unknown encapsulated variable");
    };

    sxeval::SXEval<double> eval;
    eval.build(argv[1], resolveVariable, resolveEncapsulated);

    {
        /* first evaluation */
        x = 5.2;
        y = 10.7;
        a.setValue(1.3);
        b.setValue(-3.5);
        double result = eval.evaluate();
        printf(
            "Result: %lf for expression '%s' with x=%lf, y=%lf, a=%lf and b=%lf\n",
            result, argv[1], x, y, a.getValue(), b.getValue());
    }

    {
        /* second evaluation */
        x = 3.5;
        y = 2.0;
        a.setValue(4.9);
        b.setValue(7.8);
        double result = eval.evaluate();
        printf(
            "Result: %lf for expression '%s' with x=%lf, y=%lf, a=%lf and b=%lf\n",
            result, argv[1], x, y, a.getValue(), b.getValue());
    }

    return 0;
}
