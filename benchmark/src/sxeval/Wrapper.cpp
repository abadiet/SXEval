#include "Wrapper.hpp"
#include "../myVar.hpp"
#include <vector>
#include <functional>
#include <sxeval/SXEval.hpp>

namespace benchmark {
namespace sxeval {

void Wrapper::build(const std::string& input) {
    _eval.build(input, _resolveVariable, _resolveEncapsulated);
}

double Wrapper::execute() {
    return _eval.execute();
}

double Wrapper::interpret(const std::string& input) {
    return _eval.interpret(input, _resolveVariable, _resolveEncapsulated);
}

double& Wrapper::_resolveVariable(const std::string& var) {
    if (var.front() == 'n') {
        const std::string id = var.substr(1);
        const auto index = static_cast<size_t>(std::atoi(id.c_str()));
        return (*normalVariables)[index];
    }
    throw std::invalid_argument("Unknown variable");
}

std::function<double(void)> Wrapper::_resolveEncapsulated(
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
