#include "myVar.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <chrono>
#include "IWrapper.hpp"
#include "sxeval/WrapperCompilation.hpp"
#include "sxeval/WrapperInterpretation.hpp"
#include "chibi-scheme/Wrapper.hpp"
#include "guile/Wrapper.hpp"

#define MIN -100.0
#define MAX 100.0

/* shared variables */
std::vector<double>* normalVariables = nullptr;
std::vector<MyVar>* encapsulatedVariables = nullptr;

struct stats_t {
    std::string name;
    std::vector<long long> builds;
    std::vector<long long> evaluations;
    std::vector<double> results;
    long long totalBuild;
    long long totalEval;
};
void setupVariables(const std::string& line);
void testWrapper(benchmark::IWrapper& wrapper, const std::string& line, stats_t& stats);
std::string buildStats(stats_t& stats);

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expressions_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " expressions.lst" << std::endl;
        return 1;
    }

    /* Initialize random seed */
    srand(static_cast<unsigned int>(time(nullptr)));
    rand();

    stats_t sxevalCompilStats, sxevalInterpStats, chibiStats, guileStats;
    sxevalCompilStats.name = "SXEval - Compilation Mode";
    sxevalInterpStats.name = "SXEval - Interpretation Mode";
    chibiStats.name = "Chibi Scheme";
    guileStats.name = "GNU Guile";

    {
        /* Runs */
        std::ifstream exprFile(argv[1]);
        if (!exprFile) {
            std::cerr << "Failed to open file: " << argv[1] << std::endl;
            return 1;
        }
        std::string line;
        std::getline(exprFile, line);
        while (!line.empty()) {

            /* Setup variables */
            setupVariables(line);

            {
                /* SXEval - Compilation Mode */
                benchmark::sxeval::WrapperCompilation sxevalCompil;
                testWrapper(sxevalCompil, line, sxevalCompilStats);
            }

            {
                /* SXEval - Interpretation Mode */
                benchmark::sxeval::WrapperInterpretation sxevalInterp;
                testWrapper(sxevalInterp, line, sxevalInterpStats);
            }

            {
                /* Chibi Scheme */
                benchmark::chibi_scheme::Wrapper chibi;
                testWrapper(chibi, line, chibiStats);
            }

            {
                /* GNU Guile */
                benchmark::guile::Wrapper guile;
                testWrapper(guile, line, guileStats);
            }

            delete normalVariables;
            delete encapsulatedVariables;

            std::getline(exprFile, line);
        }
        exprFile.close();
    }

    /* Statistics */
    std::cout << buildStats(sxevalCompilStats) << std::endl;
    std::cout << buildStats(sxevalInterpStats) << std::endl;
    std::cout << buildStats(chibiStats) << std::endl;
    std::cout << buildStats(guileStats) << std::endl;

    return 0;
}

void setupVariables(const std::string& line) {
    normalVariables = new std::vector<double>();
    encapsulatedVariables = new std::vector<MyVar>();

    /* Parse the line to extract variable names */
    const std::regex pattern(R"(\b([ne]\d+)\b)");
    std::sregex_iterator it(line.begin(), line.end(), pattern);
    std::sregex_iterator end;

    while (it != end) {
        const auto varName = (*it)[0].str();
        if (varName.front() == 'n') {
            const auto index = std::stoul(varName.substr(1));
            while (index >= normalVariables->size()) {
                const auto val = MIN + (MAX - MIN) * static_cast<double>(
                    rand()) / static_cast<double>(RAND_MAX);
                normalVariables->push_back(val);
            }
        } else if (varName.front() == 'e') {
            const auto index = std::stoul(varName.substr(1));
            while (index >= encapsulatedVariables->size()) {
                encapsulatedVariables->push_back(MyVar());
                const auto val = MIN + (MAX - MIN) * static_cast<double>(
                    rand()) / static_cast<double>(RAND_MAX);
                encapsulatedVariables->back().setValue(val);
            }
        } else {
            throw std::invalid_argument("Unknown variable type: " + varName);
        }
        ++it;
    }
}

void testWrapper(benchmark::IWrapper& wrapper, const std::string& line, stats_t& stats) {
    /* Format the line */
    const auto input = wrapper.formatInput(line);

    /* Building */
    {
        const auto start = std::chrono::high_resolution_clock::now();
        wrapper.build(input);
        const auto end = std::chrono::high_resolution_clock::now();
        stats.builds.push_back(std::chrono::duration_cast<std::chrono::microseconds>(
            end - start).count());
    }

    /* Evaluation */
    {
        const auto start = std::chrono::high_resolution_clock::now();
        const auto result = wrapper.evaluate(input);
        const auto end = std::chrono::high_resolution_clock::now();
        stats.evaluations.push_back(std::chrono::duration_cast<std::chrono::microseconds>(
            end - start).count());
        stats.results.push_back(result);
    }
}

std::string buildStats(stats_t& stats) {
    std::ostringstream oss;

    oss << "### " << stats.name << std::endl;

    oss << "| Building | Evaluation | Result |" << std::endl;
    oss << "|-|-|-|" << std::endl;

    stats.totalBuild = 0;
    stats.totalEval = 0;

    const auto size = stats.builds.size();
    for (size_t i = 0; i < size; ++i) {
        oss << "| " << stats.builds[i] << " | ";
        stats.totalBuild += stats.builds[i];
        oss << stats.evaluations[i] << " | ";
        stats.totalEval += stats.evaluations[i];
        oss << stats.results[i] << " | ";
        oss << std::endl;
    }
    oss << "Average: " << std::endl
        << "| " << stats.totalBuild / static_cast<long long>(size) << " | "
        << stats.totalEval / static_cast<long long>(size) << " | "
        << std::endl;

    return oss.str();
}
