#ifndef MYOPE_HPP
#define MYOPE_HPP

#include "sxeval/AOperation.hpp"
#include <string>


/* DEFINITIONS */

class MyOpe : public sxeval::AOperation<int> {
public:
    static constexpr const char* KEY = "myope";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    MyOpe(const std::vector<sxeval::IInstruction<int>*>& args) :
        AOperation<int>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};


/* IMPLEMENTATIONS */

void MyOpe::execute() {
     getResult() = this->_args[0] * 42;
}

#endif /* MYOPE_HPP */
