#include <integration.hpp>
#include <iostream>
#include <omp.h>

double f1(double x)
{
    return 1 / log(x);
}

double f2(double x)
{
    return exp(-x * x);
}

double f3(double x, double y)
{
    return x * x + y;
}

int main(void)
{
    double a = 2;
    double b = 5;
    unsigned long n = 10000000;

    double t1 = omp_get_wtime();
    std::cout << "Trapezoidal rule: " << trapezoidal_rule(f1, a, b, n) << '\n';
    t1 = omp_get_wtime() - t1;
    std::cout << "Time: " << t1 << '\n';

    double t2 = omp_get_wtime();
    std::cout << "Midpoint rule: " << midpoint_rule(f1, a, b, n) << '\n';
    t2 = omp_get_wtime() - t2;
    std::cout << "Time: " << t2 << '\n';

    double t3 = omp_get_wtime();
    std::cout << "Monte Carlo: " << monte_carlo(f1, a, b, n) << '\n';
    t3 = omp_get_wtime() - t3;
    std::cout << "Time: " << t3 << '\n';

    double t4 = omp_get_wtime();
    std::cout << "Monte Carlo 2d: " << monte_carlo(f3, { 0, 2 }, { 1, 2 }) << '\n';
    t4 = omp_get_wtime() - t4;
    std::cout << "Time: " << t4 << '\n';

    // a = -4;
    // b = 4;

    // std::cout << "Trapezoidal rule: " << trapezoidal_rule(f2, a, b, n) << '\n';
    // std::cout << "Midpoint rule: " << midpoint_rule(f2, a, b, n) << '\n';

    return 0;
}
