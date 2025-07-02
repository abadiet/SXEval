#include "myVar.hpp"
#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>

#define MIN -100.0
#define MAX 100.0

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        std::cerr << "Example: " << argv[0] << " '(+ n0 3.4 -4.1 n1 e0 e2)'" << std::endl;
        return 1;
    }

    /* variables */
    std::vector<double> normalVar;
    std::vector<MyVar> encapsVar;

    /* resolveVariable function */
    auto resolveVariable = [&](const char* var) -> double& {
        if (*var == 'n') {
            const auto index = static_cast<size_t>(std::atoi(var + 1));
            if (index >= normalVar.size()) {
                normalVar.push_back(0.0);
                return normalVar.back();
            } else {
                return normalVar[index];
            }
        }
        throw std::invalid_argument("Unknown variable");
    };

    /* resolveEncapsulated function */
    auto resolveEncapsulated = [&](const char* var)
        -> std::function<double(void)>
    {
        if (*var == 'e') {
            const auto index = static_cast<size_t>(std::atoi(var + 1));
            if (index >= encapsVar.size()) {
                encapsVar.push_back(MyVar());
                auto& ref = encapsVar.back();
                return [&]() { return ref.getValue(); };
            } else {
                auto& ref = encapsVar[index];
                return [&]() { return ref.getValue(); };
            }
        }
        throw std::invalid_argument("Unknown encapsulated variable");
    };

    sxeval::SXEval<double> eval;

    /* ### Building ### */
    {
        const auto start = std::chrono::high_resolution_clock::now();
        eval.build(argv[1], resolveVariable, resolveEncapsulated);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Expression built in " << std::chrono::duration_cast<
            std::chrono::microseconds>(end - start) .count() << " us."
            << std::endl;
    }

    /* set random values to variable */
    for (auto& var : normalVar) {
        var = MIN + (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * (MAX - MIN);
    }
    for (auto& var : encapsVar) {
        var.setValue(MIN + (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * (MAX - MIN));
    }

    /* ### Evaluation ### */
    {
        const auto start = std::chrono::high_resolution_clock::now();
        const double result = eval.evaluate();
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Expression evaluated in " << std::chrono::duration_cast<
            std::chrono::microseconds>(end - start).count() << " us."
            << std::endl;
        std::cout << "Result: " << result << std::endl;
    }

    /* ### Direct Computation ### */
    {
        const auto start = std::chrono::high_resolution_clock::now();
        const double result = eval.compute(argv[1], resolveVariable, resolveEncapsulated);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Expression computed in " << std::chrono::duration_cast<
            std::chrono::microseconds>(end - start).count() << " us."
            << std::endl;
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
