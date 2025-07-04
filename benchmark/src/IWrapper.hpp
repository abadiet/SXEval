#ifndef BENCHMARK_IWRAPPER_HPP
#define BENCHMARK_IWRAPPER_HPP

#include "myVar.hpp"
#include <string>
#include <vector>

extern std::vector<double>* normalVariables;
extern std::vector<MyVar>* encapsulatedVariables;

namespace benchmark {

class IWrapper {
public:
    virtual ~IWrapper();

    virtual std::string formatInput(const std::string& input) = 0;
    virtual void build(const std::string& input) = 0;
    virtual double evaluate(const std::string& input) = 0;

};

} /* namespace benchmark */

#endif /* BENCHMARK_IWRAPPER_HPP */
