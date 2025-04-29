#ifndef MYVAR_HPP
#define MYVAR_HPP

class MyVar {
public:
    MyVar() : _val(0) {}

    int getValue() const { return _val; }
    void setValue(int val) { _val = val; }

private:
    int _val;

};

#endif /* MYVAR_HPP */
