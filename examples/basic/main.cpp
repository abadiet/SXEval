#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        std::cerr << "Example: " << argv[0] << " '(+ x 3 -4 y)'" << std::endl;
        return 1;
    }

    /* variables */
    int x = 0, y = 0;

    /* associates names to variables */
    auto resolveVariable = [&](const std::string& var) -> int& {
        if (var == "x") {
            return x;
        } else if (var == "y") {
            return y;
        }
        throw std::invalid_argument("Unknown variable");
    };

    /* build */
    sxeval::SXEval<int> eval;
    eval.build(argv[1], resolveVariable);

    /* print the expression tree */
    std::cout << "Expression: " << std::endl << eval << std::endl;

    {
        /* first evaluation */
        x = 5;
        y = 10;
        int result = eval.evaluate();
        printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
            argv[1], x, y);
    }

    {
        /* second evaluation */
        x = 3;
        y = 2;
        int result = eval.evaluate();
        printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
            argv[1], x, y);
    }

    return 0;
}
