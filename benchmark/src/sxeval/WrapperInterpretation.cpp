#include "WrapperInterpretation.hpp"
#include "../myVar.hpp"
#include <vector>
#include <functional>
#include <sxeval/SXEval.hpp>

#define UNUSED(x) (void)(x)

namespace benchmark {
namespace sxeval {

void WrapperInterpretation::build(const std::string& input) {
    _eval = new ::sxeval::SXEval<double>();
    UNUSED(input);
}

double WrapperInterpretation::evaluate(const std::string& input) {
    return _eval->interpret(input, _resolveVariable, _resolveEncapsulated);
}

double& WrapperInterpretation::_resolveVariable(const std::string& var) {
    if (var.front() == 'n') {
        const std::string id = var.substr(1);
        const auto index = static_cast<size_t>(std::atoi(id.c_str()));
        return (*normalVariables)[index];
    }
    throw std::invalid_argument("Unknown variable");
}

std::function<double(void)> WrapperInterpretation::_resolveEncapsulated(
    const std::string& var)
{
    if (var.front() == 'e') {
        const std::string id = var.substr(1);
        const auto index = static_cast<size_t>(std::atoi(var.c_str()));
        auto& ref = (*encapsulatedVariables)[index];
        return [&]() { return ref.getValue(); };
    }
    throw std::invalid_argument("Unknown encapsulated variable");
}

} /* namespace sxeval */
} /* namespace benchmark */
