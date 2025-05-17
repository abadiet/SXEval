#ifndef MYFUNC_HPP
#define MYFUNC_HPP

#include "sxeval/AOperation.hpp"
#include <string>


/* DEFINITIONS */

class MyFunc : public sxeval::AOperation<int> {
public:
    static constexpr const char *KEY = "myfunc";
    static constexpr const int ARITY_MIN = 1;
    static constexpr const int ARITY_MAX = 1;

    MyFunc(const std::vector<sxeval::AInstruction<int>*>& args) :
        AOperation<int>(args) {}

    void execute() override;

    inline std::string toString() const override { return KEY; }

};


/* IMPLEMENTATIONS */

void MyFunc::execute() {
     getResult() = this->getArgs()[0]->getResult() * 42;
}

#endif /* MYFUNC_HPP */
