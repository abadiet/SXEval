#include "myVar.hpp"
#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        std::cerr << "Example: " << argv[0] << " '(+ x 3 -4 y a b)'" << std::endl;
        return 1;
    }

    /* variables */
    int x = 0, y = 0;

    /* encapsulated variables */
    MyVar a, b;
    a.setValue(0);
    b.setValue(0);

    /* resolveVariable function */
    auto resolveVariable = [&](const char* var) -> int& {
        if (std::strcmp(var, "x") == 0) {
            return x;
        } else if (std::strcmp(var, "y") == 0) {
            return y;
        }
        throw std::invalid_argument("Unknown variable");
    };

    /* resolveEncapsulated function */
    auto resolveEncapsulated = [&](const char* var)
        -> std::function<int(void)>
    {
        if (std::strcmp(var, "a") == 0) {
            return [&]() { return a.getValue(); };
        } else if (std::strcmp(var, "b") == 0) {
            return [&]() { return b.getValue(); };
        }
        throw std::invalid_argument("Unknown encapsulated variable");
    };

    sxeval::SXEval<int> eval(argv[1], resolveVariable, resolveEncapsulated);

    {
        /* first evaluation */
        x = 5;
        y = 10;
        a.setValue(1);
        b.setValue(-3);
        int result = eval.evaluate();
        printf(
            "Result: %d for expression '%s' with x=%d, y=%d, a=%d and b=%d\n",
            result, argv[1], x, y, a.getValue(), b.getValue());
    }

    {
        /* second evaluation */
        x = 3;
        y = 2;
        a.setValue(4);
        b.setValue(7);
        int result = eval.evaluate();
        printf(
            "Result: %d for expression '%s' with x=%d, y=%d, a=%d and b=%d\n",
            result, argv[1], x, y, a.getValue(), b.getValue());
    }

    return 0;
}
