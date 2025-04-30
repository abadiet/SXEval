# SXEval
A generic s-expression interpreter library.

Currently supported types include:
`int`, `signed int`, `short int`, `long int`, `unsigned int`, `unsigned char`,
`unsigned long int`, `float`, `double` and `long double`.

Based on the original C library [SXEval-C](https://github.com/abadiet/SXEval-C).

## Class Diagram
<img src="https://github.com/abadiet/SXEval/blob/main/uml/class-diagram.png">

## Quick-Start
From [/examples/basic](https://github.com/abadiet/SXEval/tree/main/examples/basic)
```cpp
/* variables */
int x = 0, y = 0;

/* associates names to variables */
auto resolveVariable = [&](const char* var) -> int& {
    if (std::strcmp(var, "x") == 0) {
        return x;
    } else if (std::strcmp(var, "y") == 0) {
        return y;
    }
    throw std::invalid_argument("Unknown variable");
};

/* build */
sxeval::SXEval<int> eval(argv[1], resolveVariable);

{
    /* first evaluation */
    x = 5;
    y = 10;
    int result = eval.evaluate();
    printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
        argv[1], x, y);
}

{
    /* second evaluation */
    x = 3;
    y = 2;
    int result = eval.evaluate();
    printf("Result: %d for expression '%s' with x=%d and y=%d\n", result,
        argv[1], x, y);
}
```
```bash
❯ ./examples/examples_basic '(+ y -2 (sqrt 16) (> (^ x 2) 20))'
Result: 13 for expression '(+ y -2 (sqrt 16) (> (^ x 2) 20))' with x=5 and y=10
Result: 4 for expression '(+ y -2 (sqrt 16) (> (^ x 2) 20))' with x=3 and y=2
```

## Operands
Variable names can be anything except `true` or `false`. These are
reserved and defined as constant values `1` and `0`.

Variables can be passed to SXEval either by reference (usual way) or by
value (encapsulated way). The latter is not recommended as it is a little bit
slower. The difference is highlighted in [/examples/encapsulated-variables](https://github.com/abadiet/SXEval/tree/main/examples/encapsulated-variables).

## Operations
Custom operations can be easily added to SXEval. In addition, several ones
are available. Please note that some of them may introduce approximations if used
with floating-point types.

| Name | Key | Min Arity | Max Arity |
|------|-----|-----------|-----------|
| Addition | `+` | 2 | ∞ |
| Subtraction | `-` | 2 | ∞ |
| Multiplication | `*` | 2 | ∞ |
| Division | `/` | 2 | ∞ |
| Modulo | `%` | 2 | ∞ |
| Exponentiation | `^` | 2 | ∞ |
| Equal | `=` | 2 | ∞ |
| NotEqual | `!=` | 2 | ∞ |
| Less | `<` | 2 | ∞ |
| Greater | `>` | 2 | ∞ |
| LessOrEqual | `<=` | 2 | ∞ |
| GreaterOrEqual | `>=` | 2 | ∞ |
| LogicalAnd | `and` | 2 | ∞ |
| LogicalOr | `or` | 2 | ∞ |
| LogicalNot | `not` | 1 | 1 |
| LogicalXor | `xor` | 2 | ∞ |
| LogicalXnor | `xnor` | 2 | ∞ |
| LogicalNand | `nand` | 2 | ∞ |
| LogicalNor | `nor` | 2 | ∞ |
| AbsoluteValue | `abs` | 1 | 1 |
| Average | `avg` | 2 | ∞ |
| Ceiling | `ceil` | 1 | 1 |
| Clamp | `clamp` | 3 | 3 |
| Expm1 | `expm1` | 1 | 1 |
| Floor | `floor` | 1 | 1 |
| Hypotenuse | `hypot` | 2 | 2 |
| NaturalLogarithm | `ln` | 1 | 1 |
| Logarithm | `log` | 1 | 1 |
| Logarithm10 | `log10` | 1 | 1 |
| Logarithm1p | `log1p` | 1 | 1 |
| Logarithm2 | `log2` | 1 | 1 |
| LogarithmB | `logB` | 2 | 2 |
| Maximum | `max` | 2 | ∞ |
| Minimum | `min` | 2 | ∞ |
| Round | `round` | 1 | 1 |
| SquareRoot | `sqrt` | 1 | 1 |
| Truncate | `trunc` | 1 | 1 |
| ArcCosine | `acos` | 1 | 1 |
| ArcCosh | `acosh` | 1 | 1 |
| ArcSine | `asin` | 1 | 1 |
| ArcSinh | `asinh` | 1 | 1 |
| ArcTangent | `atan` | 1 | 1 |
| ArcTangent2 | `atan2` | 2 | 2 |
| ArcTanh | `atanh` | 1 | 1 |
| Cosine | `cos` | 1 | 1 |
| Cosh | `cosh` | 1 | 1 |
| Sine | `sin` | 1 | 1 |
| Sinh | `sinh` | 1 | 1 |
| Tangent | `tan` | 1 | 1 |
| Tanh | `tanh` | 1 | 1 |
| DegreesToRadians | `deg2rad` | 1 | 1 |
| RadiansToDegrees | `rad2deg` | 1 | 1 |
| DegreesToGradians | `deg2grad` | 1 | 1 |
| GradiansToDegrees | `grad2deg` | 1 | 1 |

## Options
- `BUILD_EXAMPLES`: Build examples
- `UPDATE_SUBMODULES`: Update and download submodules
- `SXEVAL_DEBUG`: Print debug informations

## Dependencies
- [sfsexp](https://github.com/mjsottile/sfsexp): included as a submodule
- Requires at least C++17
