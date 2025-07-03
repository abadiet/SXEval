#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

#define UNUSED(x) (void)(x)

int main(int argc, char** argv) {
    /* expressions */
    const std::string expression1 = "(+ x y 3)";
    const std::string expression2 = "(* x -1 y)";

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

    /* ### EXECUTE ### */
    sxeval::SXEval<int> eval;
    eval.build(expression1, resolveVariable); /* requires a build step */
    {
        /* first evaluation */
        x = 5;
        y = 10;
        int result = eval.execute(); /* really fast evaluation */
        std::cout << "Result: " << result << " for expression '" << expression1
              << "' with x=" << x << " and y=" << y << std::endl;
    }
    {
        /* second evaluation */
        x = 3;
        y = 2;
        int result = eval.execute(); /* as fast as the first one */
        std::cout << "Result: " << result << " for expression '" << expression1
              << "' with x=" << x << " and y=" << y << std::endl;
    }
    /* however we have to instanciate and build a new sxeval::SXEval<int> object
    to evaluate anothe expression such as expression2... */

    /* ### INTERPRET ### */
    {
        /* first evaluation */
        x = 5;
        y = 10;
        int result = eval.interpret(expression1, resolveVariable); /* slow */
        std::cout << "Result: " << result << " for expression '" << expression1
              << "' with x=" << x << " and y=" << y << std::endl;
    }
    {
        /* second evaluation */
        x = 3;
        y = 2;
        int result = eval.interpret(expression2, resolveVariable); /* slow */
        std::cout << "Result: " << result << " for expression '" << expression2
              << "' with x=" << x << " and y=" << y << std::endl;
    }
    /* interpret() is slower than execute() but stil faster than build() +
    execute(). Then, it is a good choice for one-time evaulations while
    execute() is better for frequent evaluations. */

    return 0;
    UNUSED(argc);
    UNUSED(argv);
}
