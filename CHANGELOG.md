# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

> [!WARNING]
> The user API is considered to be limited to the class [`SXEval`](https://github.com/abadiet/SXEval/blob/v1.0/include/sxeval/SXEval.hpp) and its
> [operations](https://github.com/abadiet/SXEval/blob/v1.0/include/sxeval/operations).
> Backward compatibility is not guaranteed outside.

## Untracked
### Fixed
- AppleClang 17.0.0.17000319 compilation errors

## [v1.0.4] - 2025-09-16
### Added
- Benchmark
- SXEval::eval -> SXEval::execute
- SXEval::compute -> SXEval::interpret
- Exp operation
- Default operation settings
- C++11 compliance
- optimization: less copy
### Removed
- Clamp operation (> C++11)
### Fixed
- generate-operations.py

## [v1.0.3] - 2025-07-02
### Added
- Direct computation without building the expression tree.
- S-expression generator script.
- examples/benchmark
- Documentations

## [v1.0.2] - 2025-05-17
### Added
- sxeval::operations::OperationsFactory::add
- sxeval::SXEval::build
- examples/custom-operations

## [v1.0.1] - 2025-05-09
### Added
- Printing functions
### Fixed
- Fix math tests virtual class instantiation

## [v1.0.0] - 2025-05-09
### Added
- Initial implementation of the library
- Basic unit tests using [catch2](https://github.com/catchorg/Catch2)
- CMake build system
