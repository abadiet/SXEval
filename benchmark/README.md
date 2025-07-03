# Benchmark

Average duration in microseconds for 1000 complex mathematical s-expressions (c.f. [expressions.lst](https://github.com/abadiet/SXEval/tree/v1.0/benchmark/expressions.lst)).

**CPU**: Apple M3

Phases (c.f [/examples/execute-vs-interpret](https://github.com/abadiet/SXEval/tree/v1.0/examples/execute-vs-interpret)):
- *Building*: Compiles an expression to optimize its execution.
- *Execution*: Evaluates a pre-built, constant expression (though it may reference non-constant variables). Requires a one-time *Building* step, after which the expression is immutable but can be executed efficiently multiple times.
- *Interpretation*: Evaluates any expression directly, without prior building. Combines a lightweight build and execution step, making it ideal for one-time or infrequent evaluations.

> [!NOTE]
> If a project does not have an *Execution* phase but only an *Interpretation* one, the first is replaced by the latter. 

> [!NOTE]
> The other project are not limited to s-expressions, but are rather general purposes scripting language based on s-expressions (c.f. [Scheme](https://en.wikipedia.org/wiki/Scheme_(programming_language))). The reason of this selection is that I have not found any s-expression focused interpreter library.
> This benchmark however focused on mathematical s-expressions evaluation.

| | Building | Execution | Interpretation |
|-|-|-|-|
| [SXEval](https://github.com/abadiet/SXEval) | 5121 | 16 | 5004 |
| [Chibi Scheme](https://github.com/ashinn/chibi-scheme/) | 99 | 26987 | 25709 |
| [GNU Guile](https://www.gnu.org/software/guile/) | | | |
| [s7](https://ccrma.stanford.edu/software/s7/s7.html) | | | |
