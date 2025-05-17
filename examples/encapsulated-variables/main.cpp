#include "MyVar.hpp"
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
    auto resolveVariable = [&](const char* var) -> double& {
        if (std::strcmp(var, "x") == 0) {
            return x;
        } else if (std::strcmp(var, "y") == 0) {
            return y;
        }
        throw std::invalid_argument("Unknown variable");
    };

    /* resolveEncapsulated function */
    auto resolveEncapsulated = [&](const char* var)
        -> std::function<double(void)>
    {
        if (std::strcmp(var, "a") == 0) {
            return [&]() { return a.getValue(); };
        } else if (std::strcmp(var, "b") == 0) {
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
