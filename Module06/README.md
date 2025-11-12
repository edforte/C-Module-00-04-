# CPP Module 06

## Overview
This module covers C++ type casting operators, scalar type conversions, serialization/deserialization, and runtime type identification.

## Exercises

### Exercise 00: Scalar Converter
**Objective**: Convert string literals to char, int, float, and double types.

**Files**:
- `ScalarConverter.hpp` / `ScalarConverter.cpp`
- `main.cpp`
- `Makefile`

**Compilation**:
```bash
cd ex00
make
```

**Usage**:
```bash
./convert 'a'
./convert 42
./convert 42.42f
./convert nan
./convert +inf
```

**Key Concepts**:
- `static_cast` for numeric conversions
- Detection of char, int, float, double, and pseudo-literals (nan, inf)
- Handling impossible conversions and overflow
- Static-only class (non-instantiable)

---

### Exercise 01: Serialization
**Objective**: Serialize and deserialize Data pointers using `reinterpret_cast`.

**Files**:
- `Data.hpp`
- `Serializer.hpp` / `Serializer.cpp`
- `main.cpp`
- `Makefile`

**Compilation**:
```bash
cd ex01
make
```

**Usage**:
```bash
./serialize
```

**Key Concepts**:
- `reinterpret_cast` for pointer ↔ integer conversion
- `uintptr_t` type for storing pointer values
- Pointer integrity verification
- Static-only class

---

### Exercise 02: Type Identification
**Objective**: Identify actual type of Base class pointer/reference at runtime.

**Files**:
- `Base.hpp` / `Base.cpp`
- `A.hpp`, `B.hpp`, `C.hpp`
- `Functions.hpp` / `Functions.cpp`
- `main.cpp`
- `Makefile`

**Compilation**:
```bash
cd ex02
make
```

**Usage**:
```bash
./identify
```

**Key Concepts**:
- `dynamic_cast` for runtime type identification
- Pointer version: returns `nullptr` on failure
- Reference version: throws `std::bad_cast` on failure
- No use of `typeinfo` or `typeid`
- Polymorphic base class with virtual destructor

---

## Type Casting Summary

| Cast | Purpose | Safety | Example |
|------|---------|--------|---------|
| `static_cast` | Well-defined conversions | Compile-time | `static_cast<int>(3.14)` |
| `dynamic_cast` | Runtime type checking | Runtime (safe) | `dynamic_cast<Derived*>(base)` |
| `reinterpret_cast` | Bit reinterpretation | Unsafe | `reinterpret_cast<uintptr_t>(ptr)` |
| `const_cast` | Add/remove const | Can break const | `const_cast<int*>(constPtr)` |

## Testing

Each exercise includes comprehensive test cases in `main.cpp`:
- **ex00**: Various input types, edge cases, pseudo-literals
- **ex01**: Pointer integrity verification with multiple objects
- **ex02**: Random generation and specific type identification

## Compilation Standard
All exercises use C++98 standard:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Notes
- Orthodox Canonical Form implemented where required
- Static-only classes prevent instantiation
- All memory properly managed (no leaks)
- Proper exception handling in ex02 reference version
