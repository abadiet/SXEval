# SXEval
S-expression interpreter library

Based on the origianl C library [SXEval-C](https://github.com/abadiet/SXEval-C).

## Class Diagram
<img src="https://github.com/abadiet/SXEval/blob/9b7fd0497e0b8c030360df2f5aaf98d8a6e2e0f3/uml/class-diagram.png">

## Examples
```cpp
int x = 0, y = 0;  /* variables */

auto resolveVariable = [&](const char* var) -> int& {
    if (strcmp(var, "x") == 0) {
        return x;
    } else if (strcmp(var, "y") == 0) {
        return y;
    }
    throw std::invalid_argument("Unknown variable");
};

sxeval::SXEval<int> eval("(+ 2 x (+ 3 4 y) -3 y)", resolveVariable);

{
    x = 5;
    y = 10;
    int result = eval.evaluate();
    printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
        argv[1], x, y);
}

{
    x = 3;
    y = 2;
    int result = eval.evaluate();
    printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
        argv[1], x, y);
}
```
```bash
Result: 31 for expression '(+ 2 x (+ 3 4 y) -3 y)' with x=5 and y=10
Result: 13 for expression '(+ 2 x (+ 3 4 y) -3 y)' with x=3 and y=2
```

## Options
- ```BUILD_EXAMPLES```: Build examples
- ```UPDATE_SUBMODULES```: Update and download submodules
- ```SXEVAL_DEBUG```: Print debug informations

## Dependencies
- [sfsexp](https://github.com/mjsottile/sfsexp): included as a submodule
