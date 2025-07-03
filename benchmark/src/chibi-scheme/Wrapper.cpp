#include "Wrapper.hpp"
#include "../myVar.hpp"
#include <iostream>
#include <regex>

#define UNUSED(x) (void)(x)

namespace benchmark {
namespace chibi_scheme {

Wrapper::~Wrapper() {
    sexp_destroy_context(_ctx);
}

std::string Wrapper::formatInput(const std::string& input) {
    auto result = std::regex_replace(input, std::regex(R"(\b([ne]\d+)\b)"), R"((get "$1"))");
    result = std::regex_replace(result, std::regex(R"(\bceil\b)"), "ceiling");
    result = std::regex_replace(result, std::regex(R"(\btrunc\b)"), "truncate");
    result = std::regex_replace(result, std::regex(R"(\batan\b)"), "atan1");
    return result;
}

void Wrapper::build(const std::string& input) {
    _input = input;
    normalVariables->clear();
    encapsulatedVariables->clear();
    sexp_scheme_init();
    _ctx = sexp_make_eval_context(NULL, NULL, NULL, 0, 0);
    _env = sexp_context_env(_ctx);
    sexp_define_foreign(_ctx, _env, "get", 1, &_resolve);
    sexp_eval_string(_ctx, "(import (scheme base) (scheme math))", -1, _env);
}

double Wrapper::interpret(const std::string& input) {
    const auto res = sexp_eval_string(_ctx, input.c_str(), -1, _env);
    return sexp_flonum_value(res);
}

sexp Wrapper::_resolve(sexp ctx, sexp self, sexp_sint_t n, sexp exp) {
    const auto name = sexp_string_data(exp);
    const auto index = static_cast<size_t>(std::atoi(name + 1));
    if (*name == 'n') {
        return sexp_make_flonum(ctx, (*normalVariables)[index]);
        } else if (*name == 'e') {
        return sexp_make_flonum(ctx,
            (*encapsulatedVariables)[index].getValue());
    }
    throw std::runtime_error("Unknown variable type: " + std::string(name));
    UNUSED(self);
    UNUSED(n);
}

} /* namespace chibi_scheme */
} /* namespace benchmark */
