# Benchmark

Average durations in microseconds for 1000 complex mathematical s-expressions (c.f. [expressions.lst](https://github.com/abadiet/SXEval/tree/v1.0/benchmark/expressions.lst)).

**CPU**: Apple M3

> [!NOTE]
> The other project are not limited to s-expressions, but are rather general purposes scripting language based on s-expressions (c.f. [Scheme](https://en.wikipedia.org/wiki/Scheme_(programming_language))). The reason of this selection is that I have not found any s-expression focused interpreter library.
> This benchmark however focused on mathematical s-expressions evaluation.

| | Building | Evaluation | Comparison to Best |
|-|-|-|-|
| [SXEval - Compiler Mode](https://github.com/abadiet/SXEval) | 3420 | 13 | *reference* |
| [SXEval - Interpreter Mode](https://github.com/abadiet/SXEval) | 3 | 3347 | x250 |
| [GNU Guile](https://www.gnu.org/software/guile/) | 31 | 5092 | x400 |
| [Chibi Scheme](https://github.com/ashinn/chibi-scheme/) | 100 | 11345 | x900 |
| [s7](https://ccrma.stanford.edu/software/s7/s7.html) | | | |

## Dependencies

- [Chibi Scheme](https://github.com/ashinn/chibi-scheme/) (included as a submodule)
- [GNU Guile](https://www.gnu.org/software/guile/)
