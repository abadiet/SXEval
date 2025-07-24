# SXEval
A very fast, generic s-expression compiler & interpreter library.

*400x faster than [GNU Guile](https://www.gnu.org/software/guile/)...*

Based on the original C library [SXEval-C](https://github.com/abadiet/SXEval-C).

## Modes
c.f [/examples/compiler-vs-interpreter-modes](https://github.com/abadiet/SXEval/tree/v1.0/examples/compiler-vs-interpreter-modes)

### Compiler Mode
Evaluates a pre-built, constant expression (though it may reference non-constant variables). Requires a one-time building step, after which the expression is immutable but can be executed efficiently multiple times.

### Interpreter Mode
Evaluates any expression directly, without prior building. Combines a lightweight build and execution step, making it ideal for one-time or infrequent evaluations.

## Benchmark
Average durations in microseconds for 1000 complex mathematical s-expressions (c.f. [/benchmark/expressions.lst](https://github.com/abadiet/SXEval/tree/v1.0/benchmark/expressions.lst)).

| | Building | Evaluation | Comparison to Best |
|-|-|-|-|
| [SXEval - Compiler Mode](https://github.com/abadiet/SXEval) | 3420 | 13 | *reference* |
| [SXEval - Interpreter Mode](https://github.com/abadiet/SXEval) | 3 | 3347 | x250 |
| [GNU Guile](https://www.gnu.org/software/guile/) | 31 | 5092 | x400 |
| [Chibi Scheme](https://github.com/ashinn/chibi-scheme/) | 100 | 11345 | x900 |
| [s7](https://ccrma.stanford.edu/software/s7/s7.html) | | | |

c.f [/benchmark](https://github.com/abadiet/SXEval/tree/v1.0/benchmark)

## Quick-Start
From [/examples/basic](https://github.com/abadiet/SXEval/tree/v1.0/examples/basic)
```cpp
/* variables */
int x = 0, y = 0;

/* associates names to variables */
auto resolveVariable = [&](const std::string& var) -> int& {
    if (var == "x") {
        return x;
    } else if (var == "y") {
        return y;
    }
    throw std::invalid_argument("Unknown variable");
};

/* build */
sxeval::SXEval<int> eval;
eval.build(argv[1], resolveVariable);

/* print the expression tree */
std::cout << eval << std::endl;

{
    /* first evaluation */
    x = 5;
    y = 10;
    int result = eval.execute();
    std::cout << "Result: " << result << " for expression '" << argv[1]
        << "' with x=" << x << " and y=" << y << std::endl;
}

{
    /* second evaluation */
    x = 3;
    y = 2;
    int result = eval.execute();
    std::cout << "Result: " << result << " for expression '" << argv[1]
        << "' with x=" << x << " and y=" << y << std::endl;
}
```
```
$ ./examples/basic '(+ y -2 (sqrt 16) (> (^ x 2) 20))'
+
├─ y
├─ -2
├─ sqrt
│  └─ 16
└─ >
   ├─ ^
   │  ├─ x
   │  └─ 2
   └─ 20

Result: 13 for expression '(+ y -2 (sqrt 16) (> (^ x 2) 20))' with x=5 and y=10
Result: 4 for expression '(+ y -2 (sqrt 16) (> (^ x 2) 20))' with x=3 and y=2
```

## Operands

Supported types include:
`int`, `signed char`, `short int`, `long int`, `unsigned int`, `unsigned char`,
`unsigned long int`, `float`, `double` and `long double`.

Variable names can be anything except `true` or `false`. These are
reserved and defined as constant values `1` and `0`.

Variables can be passed to SXEval either by reference (usual way) or by
value (encapsulated way). The latter is not recommended as it is a little bit
slower. The difference is highlighted in [/examples/encapsulated-variables](https://github.com/abadiet/SXEval/tree/main/examples/encapsulated-variables).

## Operations
Custom operations can be easily added to SXEval. In addition, several ones
are available. Please note that some of them may introduce approximations if used
with floating-point types.

| Name | Key | Min Arity | Max Arity | Details |
|------|-----|-----------|-----------|---------|
| Addition | `+` | 2 | ∞ |  |
| Subtraction | `-` | 2 | ∞ | First argument substracted by the other ones `arg0 - arg1 - arg2 ...` |
| Multiplication | `*` | 2 | ∞ |  |
| Division | `/` | 2 | ∞ | First argument divided by the other ones `arg0 / arg1 / arg2 ...` |
| Modulo | `%` | 2 | ∞ | First argument modulo the other ones `arg0 % arg1 % arg2 ...` |
| Exponentiation | `^` | 2 | ∞ | First argument exponentiate by the other ones `arg0 ^ arg1 ^ arg2 ...` |
| Equal | `=` | 2 | ∞ | Return `true` (i.e. `1`) if all the arguments are equal |
| NotEqual | `!=` | 2 | ∞ | Return `true` (i.e. `1`) if all the arguments are not equal |
| Less | `<` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments are sorted in strict ascending order. |
| Greater | `>` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments are sorted in strict descending order. |
| LessOrEqual | `<=` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments are sorted in non-strict ascending order. |
| GreaterOrEqual | `>=` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments are sorted in non-strict descending order. |
| LogicalAnd | `and` | 2 | ∞ | Return `true` (i.e. `1`) if all the arguments are `true` (i.e. not `0`). |
| LogicalOr | `or` | 2 | ∞ | Return `true` (i.e. `1`) if at least one of the arguments is `true` (i.e. not `0`). |
| LogicalNot | `not` | 1 | 1 | Return `true` (i.e. `1`) if the argument is `false` (i.e. `0`). |
| LogicalXor | `xor` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments, as boolean values, are not all equal. |
| LogicalXnor | `xnor` | 2 | ∞ | Return `true` (i.e. `1`) if the arguments, as boolean values, are all equal. |
| LogicalNand | `nand` | 2 | ∞ | Return `true` (i.e. `1`) if at least one of the arguments is `false` (i.e. `0`). |
| LogicalNor | `nor` | 2 | ∞ | Return `true` (i.e. `1`) if all the arguments are `false` (i.e. `0`). |
| AbsoluteValue | `abs` | 1 | 1 |  |
| Average | `avg` | 2 | ∞ |  |
| Ceiling | `ceil` | 1 | 1 | c.f. `std::ceil` |
| Clamp | `clamp` | 3 | 3 | c.f. `std::clamp` |
| Expm1 | `expm1` | 1 | 1 | c.f. `std::expm1` |
| Exp | `exp` | 1 | 1 | c.f. `std::exp` |
| Floor | `floor` | 1 | 1 | c.f. `std::floor` |
| Hypotenuse | `hypot` | 2 | 2 | c.f. `std::hypot` |
| NaturalLogarithm | `ln` | 1 | 1 | c.f. `std::log` |
| Logarithm | `log` | 1 | 1 | c.f. `std::log` |
| Logarithm10 | `log10` | 1 | 1 | c.f. `std::log10` |
| Logarithm1p | `log1p` | 1 | 1 | c.f. `std::log1p` |
| Logarithm2 | `log2` | 1 | 1 | c.f. `std::log2` |
| LogarithmB | `logB` | 2 | 2 | Logarithm base B `logB(x, base)` |
| Maximum | `max` | 2 | ∞ | c.f. `std::max` |
| Minimum | `min` | 2 | ∞ | c.f. `std::min` |
| Round | `round` | 1 | 1 | c.f. `std::round` |
| SquareRoot | `sqrt` | 1 | 1 | c.f. `std::sqrt` |
| Truncate | `trunc` | 1 | 1 | c.f. `std::trunc` |
| ArcCosine | `acos` | 1 | 1 | c.f. `std::acos` |
| ArcCosh | `acosh` | 1 | 1 | c.f. `std::acosh` |
| ArcSine | `asin` | 1 | 1 | c.f. `std::asin` |
| ArcSinh | `asinh` | 1 | 1 | c.f. `std::asinh` |
| ArcTangent | `atan` | 1 | 1 | c.f. `std::atan` |
| ArcTangent2 | `atan2` | 2 | 2 | c.f. `std::atan2` |
| ArcTanh | `atanh` | 1 | 1 | c.f. `std::atanh` |
| Cosine | `cos` | 1 | 1 | c.f. `std::cos` |
| Cosh | `cosh` | 1 | 1 | c.f. `std::cosh` |
| Sine | `sin` | 1 | 1 | c.f. `std::sin` |
| Sinh | `sinh` | 1 | 1 | c.f. `std::sinh` |
| Tangent | `tan` | 1 | 1 | c.f. `std::tan` |
| Tanh | `tanh` | 1 | 1 | c.f. `std::tanh` |
| DegreesToRadians | `deg2rad` | 1 | 1 |  |
| RadiansToDegrees | `rad2deg` | 1 | 1 |  |
| DegreesToGradians | `deg2grad` | 1 | 1 |  |
| GradiansToDegrees | `grad2deg` | 1 | 1 |  |


## Class Diagram
<img src="https://raw.githubusercontent.com/abadiet/SXEval/refs/heads/v1.0/uml/class-diagram.png?raw=true" style="max-width: 100%;">

## Options
- `BUILD_EXAMPLES`: Build examples
- `BUILD_TESTS`: Build tests
- `BUILD_BENCHMARK`: Build benchmark
- `SXEVAL_DEBUG`: Print debug information

## ChangeLog
> [!WARNING]
> The user API is considered to be limited to the class [`SXEval`](https://github.com/abadiet/SXEval/blob/v1.0/include/sxeval/SXEval.hpp) and its
> [operations](https://github.com/abadiet/SXEval/blob/v1.0/include/sxeval/operations).
> Backward compatibility is not guaranteed outside.

c.f. [CHANGELOG.md](https://github.com/abadiet/SXEval/blob/v1.0/CHANGELOG.md)

## Dependencies
- [catch2](https://github.com/catchorg/Catch2): testing frameworks (fetch by
cmake if option `BUILD_EXAMPLES` is enabled)
- [Chibi Scheme](https://github.com/ashinn/chibi-scheme/): for benchmarking (included as a submodule)
- [GNU Guile](https://www.gnu.org/software/guile/): for benchmarking
- Requires at least C++20: for concepts (c.f. [OperationsFactory](https://github.com/abadiet/SXEval/blob/v1.0/include/sxeval/operations/OperationsFactory.hpp))
