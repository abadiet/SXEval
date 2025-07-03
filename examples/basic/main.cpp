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
    std::cout << eval << std::endl;

    {
        /* first evaluation */
        x = 5;
        y = 10;
        int result = eval.execute();
        std::cout << "Result: " << result << " for expression '" << argv[1]
            << "' with x=" << x << " and y=" << y << std::endl;
    }

    {
        /* second evaluation */
        x = 3;
        y = 2;
        int result = eval.execute();
        std::cout << "Result: " << result << " for expression '" << argv[1]
            << "' with x=" << x << " and y=" << y << std::endl;
    }

    return 0;
}
