#include <integration.hpp>
#include <iostream>

double f1(double x)
{
    return 1 / log(x);
}

double f2(double x)
{
    return exp(-x * x);
}

int main(void)
{
    double a = 2;
    double b = 5;
    unsigned long n = 10000000;

    std::cout << "Trapezoidal rule: " << trapezoidal_rule(f1, a, b) << '\n';
    std::cout << "Midpoint rule: " << midpoint_rule(f1, a, b) << '\n';

    a = -4;
    b = 4;

    std::cout << "Trapezoidal rule: " << trapezoidal_rule(f2, a, b) << '\n';
    std::cout << "Midpoint rule: " << midpoint_rule(f2, a, b) << '\n';

    return 0;
}
