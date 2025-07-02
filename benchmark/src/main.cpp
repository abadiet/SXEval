#include "myVar.hpp"
#include <sxeval/SXEval.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <chrono>

#define MIN -100.0
#define MAX 100.0

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expressions_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " expressions.lst" << std::endl;
        return 1;
    }

    std::vector<long long> builds;
    std::vector<long long> evaluations;
    std::vector<long long> computations;
    std::vector<double> resultsEval;
    std::vector<double> resultsComp;

    std::ifstream exprFile(argv[1]);
    if (!exprFile) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }
    std::string line;
    std::getline(exprFile, line);
    while (!line.empty()) {
        /* variables */
        std::vector<double> normalVar;
        std::vector<MyVar> encapsVar;

        /* resolveVariable function */
        auto resolveVariable = [&](const std::string& var) -> double& {
            if (var.front() == 'n') {
                const std::string id = var.substr(1);
                const auto index = static_cast<size_t>(std::atoi(id.c_str()));
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
        auto resolveEncapsulated = [&](const std::string& var)
            -> std::function<double(void)>
        {
            if (var.front() == 'e') {
                const std::string id = var.substr(1);
                const auto index = static_cast<size_t>(std::atoi(var.c_str()));
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
            eval.build(line, resolveVariable, resolveEncapsulated);
            const auto end = std::chrono::high_resolution_clock::now();
            builds.push_back(std::chrono::duration_cast<
                std::chrono::microseconds>(end - start).count());
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
            evaluations.push_back(std::chrono::duration_cast<
                std::chrono::microseconds>(end - start).count());
            resultsEval.push_back(result);
        }

        /* ### Direct Computation ### */
        {
            const auto start = std::chrono::high_resolution_clock::now();
            const double result = eval.compute(line, resolveVariable, resolveEncapsulated);
            const auto end = std::chrono::high_resolution_clock::now();
            computations.push_back(std::chrono::duration_cast<
                std::chrono::microseconds>(end - start).count());
            resultsComp.push_back(result);
        }

        std::getline(exprFile, line);
    }
    exprFile.close();

    long long totalBuild = 0;
    long long totalEval = 0;
    long long totalComp = 0;
    const auto size = builds.size();
    std::cout << "Building | Evaluation | Computation | Evaluation Result | Computation Result" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << builds[i] << " | " << evaluations[i] << " | "
            << computations[i] << " | " << resultsEval[i] << " | "
            << resultsComp[i] << std::endl;
        totalBuild += builds[i];
        totalEval += evaluations[i];
        totalComp += computations[i];
    }
    std::cout << "Average: " << std::endl
        << totalBuild / static_cast<long long>(size) << " | "
        << totalEval / static_cast<long long>(size) << " | "
        << totalComp / static_cast<long long>(size) << std::endl;

    return 0;
}
