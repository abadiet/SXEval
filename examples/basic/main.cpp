#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }

    int x = 0, y = 0;

    auto resolveVariable = [&](const char* var) -> int& {
        if (std::strcmp(var, "x") == 0) {
            return x;
        } else if (std::strcmp(var, "y") == 0) {
            return y;
        }
        throw std::invalid_argument("Unknown variable");
    };

    sxeval::SXEval<int> eval(argv[1], resolveVariable);

    {
        x = 5;
        y = 10;
        int result = eval.evaluate();
        printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
            argv[1], x, y);
    }

    {
        x = 3;
        y = 2;
        int result = eval.evaluate();
        printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
            argv[1], x, y);
    }

    return 0;
}
