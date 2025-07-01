#ifndef MYVAR_HPP
#define MYVAR_HPP

class MyVar {
public:
    MyVar() : _val(0) {}

    inline double getValue() const { return _val; }
    inline void setValue(double val) { _val = val; }

private:
    double _val;

};

#endif /* MYVAR_HPP */
