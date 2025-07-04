#ifndef BENCHMARK_GUILE_WRAPPER_HPP
#define BENCHMARK_GUILE_WRAPPER_HPP

#include <libguile.h>
#include <string>
#include <functional>
#include "../IWrapper.hpp"

namespace benchmark {
namespace guile {

class Wrapper : public benchmark::IWrapper {
public:
    inline Wrapper() {}
    ~Wrapper() override = default;

    std::string formatInput(const std::string& input) override;
    void build(const std::string& input) override;
    double evaluate(const std::string& input) override;

};

} /* namespace guile */
} /* namespace benchmark */

#endif /* BENCHMARK_GUILE_WRAPPER_HPP */
