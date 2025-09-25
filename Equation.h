//
// Created by royivri on 9/21/25.
//

#ifndef EQUATION_H
#define EQUATION_H
#include <cstddef>
#include <stdexcept>


class Equation {
public:

    Equation(double a_, double b_, double c_);
    Equation(const Equation& other);
    Equation& operator=(const Equation& other);
    ~Equation();



    double getA() const;

    double getB() const;

    double getC() const;

    double const *get_solutions() const;

    std::size_t get_solutions_size() const;

    void setA(double a_);

    void setB(double b_);

    void setC(double c_);





    friend std::ostream &operator<<(std::ostream &os, const Equation &eq);
    friend Equation operator+(const Equation &lhs, const Equation &rhs);
    friend Equation operator+(const Equation &lhs, double rhs);
    friend Equation operator+(double lhs, const Equation &rhs);

private:
    double a;
    double b;
    double c;
    double *solutions;
    std::size_t solutions_size;
    void setSolutionsSize(std::size_t size_);
    void update_solutions();

    std::size_t check_solution_size();
};


#endif //EQUATION_H
