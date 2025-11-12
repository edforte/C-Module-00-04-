# CPP Module 05

Complete implementation of 42's CPP Module 05 focusing on C++ exceptions, inheritance, abstract classes, and the Orthodox Canonical Form.

## 📁 Structure

```
Module05/
├── ex00/           # Bureaucrat class with exception handling
├── ex01/           # Form class with signing mechanism
├── ex02/           # Abstract forms and concrete implementations
└── ex03/           # Intern class for form creation
```

## 🎯 Exercises Overview

### Exercise 00: Bureaucrat
- Implementation of the Bureaucrat class
- Grade system (1-150, where 1 is highest)
- Custom exception classes (GradeTooHighException, GradeTooLowException)
- Grade increment/decrement with validation
- Overloaded insertion operator

**Files:**
- `Bureaucrat.hpp` / `Bureaucrat.cpp`
- `main.cpp` (comprehensive tests)
- `Makefile`

**Compilation:**
```bash
cd ex00
make
./bureaucrat
```

### Exercise 01: Form
- Implementation of the Form class
- Signing mechanism with bureaucrats
- Grade requirements for signing and execution
- Integration with Bureaucrat class
- Form status tracking

**Files:**
- `Bureaucrat.hpp` / `Bureaucrat.cpp` (updated with signForm)
- `Form.hpp` / `Form.cpp`
- `main.cpp` (form signing tests)
- `Makefile`

**Compilation:**
```bash
cd ex01
make
./form
```

### Exercise 02: Abstract Forms
- Abstract base class AForm (renamed from Form)
- Three concrete form implementations:
  - **ShrubberyCreationForm** (sign: 145, exec: 137)
    - Creates ASCII tree file `<target>_shrubbery`
  - **RobotomyRequestForm** (sign: 72, exec: 45)
    - 50% success rate robotomy with drilling noises
  - **PresidentialPardonForm** (sign: 25, exec: 5)
    - Presidential pardon by Zaphod Beeblebrox
- Execute method with proper validation
- Bureaucrat executeForm method

**Files:**
- `Bureaucrat.hpp` / `Bureaucrat.cpp` (updated with executeForm)
- `AForm.hpp` / `AForm.cpp` (abstract base)
- `ShrubberyCreationForm.hpp` / `.cpp`
- `RobotomyRequestForm.hpp` / `.cpp`
- `PresidentialPardonForm.hpp` / `.cpp`
- `main.cpp` (all forms tests)
- `Makefile`

**Compilation:**
```bash
cd ex02
make
./forms
```

### Exercise 03: Intern
- Intern class for dynamic form creation
- Elegant implementation using function pointers
- makeForm method with form name and target
- No messy if/else chains
- Proper error handling for unknown forms

**Files:**
- All files from ex02
- `Intern.hpp` / `Intern.cpp`
- `main.cpp` (intern tests)
- `Makefile`

**Compilation:**
```bash
cd ex03
make
./intern
```

## 🔧 Compilation Requirements

All exercises compile with:
- **Compiler:** `c++`
- **Flags:** `-Wall -Wextra -Werror -std=c++98`
- No external libraries (except standard library)

## 🧪 Testing

Each exercise includes comprehensive tests in `main.cpp`:

### ex00 Tests:
- Valid bureaucrat creation
- Grade too high/low exceptions
- Increment/decrement operations
- Copy constructor and assignment operator
- Edge cases (boundaries)

### ex01 Tests:
- Form creation with valid/invalid grades
- Successful form signing
- Failed signing (insufficient grade)
- Multiple signing attempts
- Edge cases

### ex02 Tests:
- All three form types execution
- Execution without signing
- Insufficient grade to execute/sign
- All forms with CEO (grade 1)
- Grade boundaries

### ex03 Tests:
- Creating all form types via Intern
- Invalid form names
- Multiple interns
- Case sensitivity
- Memory management

## 📝 Key Concepts Implemented

### Orthodox Canonical Form
Every class (except exceptions) implements:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

### Exception Handling
- Inheritance from `std::exception`
- Custom `what()` methods
- Try-catch blocks for error handling
- Proper exception propagation

### Inheritance & Polymorphism
- Abstract base class (AForm)
- Pure virtual methods
- Virtual destructors
- Protected methods for derived classes

### Design Patterns
- Template Method (executeAction)
- Factory Method (Intern's makeForm)
- Function pointers for clean code

## 🎨 Grade System Logic

**Important:** The grade system is inverted!
- Grade **1** = HIGHEST (best)
- Grade **150** = LOWEST (worst)
- **incrementGrade()** = DECREASES number (improves grade)
- **decrementGrade()** = INCREASES number (worsens grade)

## 📊 Form Requirements

| Form Type | Sign Grade | Execute Grade |
|-----------|------------|---------------|
| Shrubbery Creation | 145 | 137 |
| Robotomy Request | 72 | 45 |
| Presidential Pardon | 25 | 5 |

## 🧹 Cleaning

Each exercise has standard Makefile rules:
```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Rebuild everything
```

Note: ex02 `fclean` also removes `*_shrubbery` files.

## 🔍 Form Names (for Intern)

The Intern recognizes these exact form names (case-sensitive):
- `"shrubbery creation"`
- `"robotomy request"`
- `"presidential pardon"`

## ⚠️ Important Notes

1. **Const Members:** The assignment operators handle const members appropriately
2. **Memory Management:** All dynamically allocated forms must be deleted
3. **Exception Safety:** Always use try-catch blocks when calling methods that may throw
4. **Virtual Destructors:** Base class AForm has virtual destructor for proper cleanup
5. **File Creation:** ShrubberyCreationForm creates files in current directory

## 🚀 Quick Start

```bash
# Test all exercises
cd Module05

# Exercise 00
cd ex00 && make && ./bureaucrat && cd ..

# Exercise 01
cd ex01 && make && ./form && cd ..

# Exercise 02
cd ex02 && make && ./forms && cd ..

# Exercise 03
cd ex03 && make && ./intern && cd ..
```

## 📚 Learning Outcomes

This module teaches:
- C++ exception handling mechanisms
- Inheritance and abstract classes
- Orthodox Canonical Form
- Const correctness
- Virtual functions and polymorphism
- Memory management with dynamic allocation
- Clean code practices (avoiding if/else chains)
- Proper error handling and validation

## ✅ Evaluation Checklist

- [x] All files compile with required flags
- [x] No memory leaks (test with valgrind)
- [x] Orthodox Canonical Form implemented
- [x] Exception classes properly defined
- [x] Grade validation working correctly
- [x] Form signing mechanism functional
- [x] Form execution with proper checks
- [x] Intern creates forms correctly
- [x] Comprehensive tests provided
- [x] Clean code without messy if/else structures

---

**Author:** Created using cpp05 skill
**Date:** 2024
**School:** 42
