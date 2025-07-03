#ifndef BENCHMARK_SXEVAL_WRAPPER_HPP
#define BENCHMARK_SXEVAL_WRAPPER_HPP

#include <sxeval/SXEval.hpp>
#include <string>
#include <vector>
#include "../myVar/myVar.hpp"

extern std::vector<double>* normalVariables;
extern std::vector<MyVar>* encapsulatedVariables;

namespace benchmark {
namespace sxeval {

class Wrapper {
public:
    inline Wrapper() {}
    ~Wrapper() = default;

    inline static std::string formatInput(const std::string& input) {
        return input; }
    void build(const std::string& input);
    double execute();
    double interpret(const std::string& input);

private:
    static double& _resolveVariable(const std::string& var);
    static std::function<double(void)> _resolveEncapsulated(
        const std::string& var);

    ::sxeval::SXEval<double> _eval;

};

} /* namespace sxeval */
} /* namespace benchmark */

#endif /* BENCHMARK_SXEVAL_WRAPPER_HPP */
