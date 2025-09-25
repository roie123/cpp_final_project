//
// Created by royivri on 9/21/25.
//

#include "Equation.h"

#include <complex>
#include <iomanip>
#include <iostream>



/**
 * @brief Construct a new Equation object with given coefficients.
 *
 * The constructor checks that the coefficient 'a' is non-zero.
 * If 'a' is zero, it throws std::invalid_argument because the equation
 * would not be quadratic.
 *
 * @param a_ Coefficient of x^2 (must be non-zero)
 * @param b_ Coefficient of x
 * @param c_ Constant term
 * @throws std::invalid_argument if a_ == 0
 */
Equation::Equation(double a_, double b_, double c_)
    : a(a_), b(b_), c(c_), solutions(nullptr), solutions_size(0)
{
    if (a_ == 0) {
        throw std::invalid_argument("Coefficient 'a' must be non-zero");
    }
}
Equation::Equation(const Equation &other)
    : a(other.a), b(other.b), c(other.c), solutions_size(other.solutions_size)
{
    if (other.solutions) {
        // Allocate a new array for solutions
        solutions = new double[solutions_size];
        for (std::size_t i = 0; i < solutions_size; ++i) {
            solutions[i] = other.solutions[i];
        }
    } else {
        solutions = nullptr;
    }



}
Equation::~Equation() {
    delete[] solutions;  // free the array of doubles
    solutions = nullptr;
}





double Equation::getA() const {
    return a;
}
double Equation::getB() const {
    return b;
}
double Equation::getC() const {
    return c;
}
double const* Equation::get_solutions() const {
    if (!solutions) {
        return nullptr; // or throw std::logic_error("Solutions not computed yet");
    }

    return solutions; // now returns pointer to the first double
}
std::size_t Equation::get_solutions_size() const {
    return this->solutions_size;
}





void Equation::setA(const double a_) {

    if (a_ == 0) {
        throw std::invalid_argument("A must be non-zero");
    } else if (a != a_) {
        a = a_;

        update_solutions();
    }
}
void Equation::setB(const double b_) {
    if (b_ != b) {
        b = b_;
        update_solutions();
    }
}
void Equation::setC(const double c_) {

    if (c != c_) {
        c = c_;
        update_solutions();
    }
}
void Equation::setSolutionsSize(std::size_t size_) {
    this->solutions_size = size_;
}







std::ostream &operator<<(std::ostream &os, const Equation &eq) {


    os << std::fixed << std::setprecision(1);

    os << eq.a << " X^2 + "
            << eq.b << " X + "
            << eq.c << " = 0";

    return os;
}



Equation operator+(const Equation &lhs, const Equation &rhs) {
    double newA = lhs.a + rhs.a;
    if (newA == 0.0) {
        throw std::invalid_argument("'a' must not be zero after addition");
    }

    return Equation(newA, lhs.b + rhs.b, lhs.c + rhs.c);
}
Equation operator+(const Equation &lhs, double rhs) {
    double newA = lhs.a;
    if (newA == 0.0) {
        throw std::invalid_argument("'a' must not be zero after addition");
    }
    return Equation(newA, lhs.b, lhs.c + rhs);
}
Equation operator+(double lhs, const Equation &rhs) {
    double newA = rhs.a;
    if (std::abs(newA) < 1e-12) { /// i dont want small percision to be a problem
        throw std::invalid_argument("'a' must not be zero after addition");
    }
    return Equation(newA, rhs.b, rhs.c + lhs);
}
/**
 * @brief Assignment operator for Equation (deep copy).
 *
 * copies all coefficients and dynamically allocated solutions from another Equation.
 * handles self-assignment safely. Old solutions memory is freed before copying.
 *
 * @param other The Equation object to copy from
 * @return Equation& Reference to this object after assignment
 * @throws std::bad_alloc If memory allocation for solutions fails
 */
Equation& Equation::operator=(const Equation &other) {
    if (this == &other) {
        return *this; // handle self-assignment
    }

    // 1. Copy simple members
    a = other.a;
    b = other.b;
    c = other.c;
    solutions_size = other.solutions_size;

    // 2. Delete old solutions
    delete[] solutions;
    solutions = nullptr;

    // 3. Deep copy new solutions
    if (other.solutions) {
        solutions = new double[solutions_size];
        for (std::size_t i = 0; i < solutions_size; ++i) {
            solutions[i] = other.solutions[i];
        }
    }

    // Optional: recompute solutions if needed
    update_solutions();

    return *this;
}









/**
 * @brief Computes the roots of the quadratic equation and stores them in the solutions array.
 *
 * If the solutions array is not yet allocated, it allocates an array of size 2.
 * Then, depending on the number of real roots determined by check_solution_size():
 * - 0 roots: both entries set to 0
 * - 1 root: both entries set to the same root
 * - 2 roots: entries set to the two distinct real roots
 *
 * @throws std::logic_error if check_solution_size() returns an unexpected value
 */
void Equation::update_solutions() {

    if (!solutions) {
        solutions_size = 2;
        solutions = new double[solutions_size];
    }

    size_t sol_size = this->check_solution_size();

    switch (sol_size) {
        case 0:
            solutions[0] = solutions[1] = 0;
            break;
        case 1:
            solutions[0] = -b / (2 * a);
            solutions[1] = solutions[0]; // same root
            break;
        case 2: {
            double discriminant = b * b - 4 * a * c;
            double sqrtD = std::sqrt(discriminant);
            solutions[0] = (-b + sqrtD) / (2 * a);
            solutions[1] = (-b - sqrtD) / (2 * a);
            break;
        }
        default:
            throw std::logic_error("Unexpected solution size");
    }
}
std::size_t Equation::check_solution_size() {
    int discriminant = std::pow(b, 2) - 4 * a * c;

    if (discriminant > 0) {
        setSolutionsSize(2);
        return 2;
    } // two real solutions
    else if (discriminant == 0) {
        setSolutionsSize(1);
        return 1;
    } // one real solution
    else { setSolutionsSize(0); }
    return 0;
}


