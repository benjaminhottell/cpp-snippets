# C++ Snippets

This repository contains small snippets of C++ code and related files that (probably) aren't worth putting into their own repository or library.

Each snippet is self-contained and independent unless otherwise documented via comments or `#include` directives.

The code in these files may be untested or buggy. You refer to them **at your own risk**.


## Building

While each snippet is self-contained, a `CMakeLists.txt` file is included to build an executable to run unit tests via [doctest](https://github.com/doctest/doctest).

The `makefile` just invokes cmake, and therefore does not do anything significant and can be ignored. Its just there for convenience.

