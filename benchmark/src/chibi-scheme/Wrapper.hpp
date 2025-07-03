#ifndef BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP
#define BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP

#include <chibi/sexp.h>
#include <string>
#include <functional>
#include "../IWrapper.hpp"

namespace benchmark {
namespace chibi_scheme {

class Wrapper : public benchmark::IWrapper {
public:
    inline Wrapper() {}
    ~Wrapper() override;

    std::string formatInput(const std::string& input) override;
    void build(const std::string& input) override;
    inline double execute() override { return interpret(_input); }
    double interpret(const std::string& input) override;

private:
    static sexp _resolve(sexp ctx, sexp self, sexp_sint_t n, sexp exp);

    sexp _ctx;
    sexp _env;
    std::string _input;

};

} /* namespace chibi_scheme */
} /* namespace benchmark */

#endif /* BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP */
