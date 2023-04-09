#include <iostream>
#include <ode.hpp>

double f1(double x, double y)
{
    return x * x - 2 * y;
}

double f1(double x, double y)
{
    return x * x - 2 * y;
}

int main(void)
{
    std::cout << "Euler: " << euler(f1, 0.0, 1.0, 1) << '\n';
    std::cout << "Runge-Kutta: " << runge_kutta(f1, 0.0, 1.0, 1) << '\n';
    return 0;
}
