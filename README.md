# c-unit-testing-example
An example of unit testing in C language using CuTest framework for Operating Systems Assignment at ITBA.

## Dependencies

* **C Compiler:** [Clang](https://llvm.org/)
* **Testing Framework:** [CuTest: C Unit Testing Framework
](http://cutest.sourceforge.net/)
* **Static Code Analysis Tools:** [Cppcheck](http://cppcheck.sourceforge.net/) and [PVS-Studio](https://pvs-studio.com/en/pvs-studio/)
* **Formatter:** [Clang-format](https://clang.llvm.org/docs/ClangFormat.html)

## Compile and run unit tests
To compile `MemoryManagerTest` run:
```
$> make all
$> ./MemoryManagerTest.out
```

## Static Code Analysis
To execute the static code analysis tools `Cppcheck` and `PVS-Studio` run:
```
$> make check
```

## Formating
To execute the code formatter `Clang-format` run:
```
$> make format
```

