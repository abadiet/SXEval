#ifndef BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP
#define BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP

#include "../myVar/myVar.hpp"
#include <chibi/sexp.h>
#include <string>
#include <vector>
#include <functional>

extern std::vector<double>* normalVariables;
extern std::vector<MyVar>* encapsulatedVariables;

namespace benchmark {
namespace chibi_scheme {

class Wrapper {
public:
    inline Wrapper() {}
    ~Wrapper();

    static std::string formatInput(const std::string& input);
    void build(const std::string& input);
    inline double execute() { return interpret(_input); }
    double interpret(const std::string& input);

private:
    static sexp _resolve(sexp ctx, sexp self, sexp_sint_t n, sexp exp);

    sexp _ctx;
    sexp _env;
    std::string _input;

};

} /* namespace chibi_scheme */
} /* namespace benchmark */

#endif /* BENCHMARK_CHIBI_SCHEME_WRAPPER_HPP */
