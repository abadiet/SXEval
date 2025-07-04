#ifndef BENCHMARK_SXEVAL_WRAPPER_COMPILATION_HPP
#define BENCHMARK_SXEVAL_WRAPPER_COMPILATION_HPP

#include <sxeval/SXEval.hpp>
#include <string>
#include "../IWrapper.hpp"

namespace benchmark {
namespace sxeval {

class WrapperCompilation : public benchmark::IWrapper {
public:
    inline WrapperCompilation() {}
    inline ~WrapperCompilation() override { delete _eval; }

    inline std::string formatInput(const std::string& input) override {
        return input; }
    void build(const std::string& input) override;
    double evaluate(const std::string& input) override;

private:
    static double& _resolveVariable(const std::string& var);
    static std::function<double(void)> _resolveEncapsulated(
        const std::string& var);

    ::sxeval::SXEval<double>* _eval;

};

} /* namespace sxeval */
} /* namespace benchmark */

#endif /* BENCHMARK_SXEVAL_WRAPPER_COMPILATION_HPP */
