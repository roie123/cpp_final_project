# C++ Final Project

This project consists of two main parts:

1. **Quadratic Equation class** – focusing on resource management, operator overloading, and the Rule of Three/Five.
2. **Animal Health Management System** – focusing on inheritance, polymorphism, and the Singleton design pattern.

---

## Task 1 – Quadratic Equation

The first task implements a class called **Equation** to represent a quadratic equation of the form:  

A * X^2 + B * X + C = 0

### Key Features
- **Private fields**:
    - `a`, `b`, `c` – coefficients of the equation.
    - `solutions` – dynamically allocated array storing up to two roots.
    - `solutions_size` – the number of valid solutions (0, 1, or 2).
- **Validation**:
    - The coefficient `a` must never be zero. Attempts to set it to zero throw `std::invalid_argument`.
- **Resource management**:
    - Fully implements the Rule of Three and Rule of Five (copy constructor, assignment operator, destructor, etc.).
    - Prevents memory leaks by careful allocation and deallocation of the `solutions` array.
- **Public interface**:
    - Accessors (`get_a`, `get_b`, `get_c`) and mutators with validation.
    - `get_solutions()` and `get_solutions_size()` for accessing computed roots.
- **Operator overloads**:
    - Stream insertion (`<<`) for formatted printing.
    - Addition operators for combining equations and constants.

This task emphasizes exception safety, deep copying, and good memory practices.

---

## Task 2 – Animal Health Management System

The second task implements an object-oriented system for monitoring animal health, using inheritance and polymorphism.

### Animal Base Class
- Abstract class representing a general animal.
- Fields: `name`, `temperature`, `breathing rate`, `heart rate`.
- Defines the pure virtual method `check_health()`, which must be implemented by all subclasses.

### Derived Classes
- **Dog**
    - Adds a field for breed size (`is_large`).
    - Implements `check_health()` with health rules that differ for large and small breeds.
- **Cat**
    - No additional fields.
    - Implements its own `check_health()` logic.
- **Cow**
    - Adds a field for milk production (`liters`).
    - Implements `check_health()` according to species-specific ranges.

### Vet Class
- A **singleton** that manages a collection of animal objects.
- Stores animals in a `std::vector` of smart pointers for safe memory management.
- Methods include:
    - Adding animals to the system.
    - Showing all sick animals.
    - Showing only sick dogs.

---

## Design Notes
- **Quadratic Equation**: The implementation deliberately uses dynamic allocation for the solutions array, even though in practice simpler alternatives exist. This is done to practice resource handling and exception safety.
- **Animal/Vet System**:
    - Demonstrates object-oriented programming principles.
    - Encapsulates data per species.
    - Uses polymorphism for `check_health()`.
    - Applies the Singleton pattern to ensure only one `Vet` instance exists.

---

## Build & Run
- Requires **C++17 or later**.
- Can be built with standard compilers such as `g++` or `clang++`.
- The program is organized into multiple source and header files for clarity.  
