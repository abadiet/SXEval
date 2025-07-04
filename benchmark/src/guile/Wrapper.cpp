#include "Wrapper.hpp"
#include "../myVar.hpp"
#include <iostream>
#include <regex>

#define UNUSED(x) (void)(x)

namespace benchmark {
namespace guile {

static SCM resolve(SCM exp) {
    const auto name = scm_to_locale_string(exp);
    const auto index = static_cast<size_t>(std::atoi(name + 1));
    if (*name == 'n') {
        return scm_from_double((*normalVariables)[index]);
        } else if (*name == 'e') {
        return scm_from_double((*encapsulatedVariables)[index].getValue());
    }
    throw std::runtime_error("Unknown variable type: " + std::string(name));
}

std::string Wrapper::formatInput(const std::string& input) {
    auto result = std::regex_replace(input, std::regex(R"(\b([ne]\d+)\b)"), R"((get "$1"))");
    result = std::regex_replace(result, std::regex(R"(\bceil\b)"), "ceiling");
    result = std::regex_replace(result, std::regex(R"(\btrunc\b)"), "truncate");
    return result;
}

void Wrapper::build(const std::string& input) {
    scm_init_guile(); /* TODO run only once per thread */
    scm_c_define_gsubr("get", 1, 0, 0, reinterpret_cast<scm_t_subr>(&resolve));
    // scm_c_eval_string("(use-modules (srfi srfi-1) (srfi srfi-13))");
    // scm_c_eval_string("(use-modules (ice-9 math))");
    UNUSED(input);
}

double Wrapper::evaluate(const std::string& input) {
    auto result = scm_c_eval_string(input.c_str());
    return scm_to_double(result);
}

} /* namespace chibi_scheme */
} /* namespace benchmark */
