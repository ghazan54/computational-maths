#include <cmath>
#include <iostream>
#include <nlequations.hpp>

double f1(double x)
{
    return pow(x, 3) + 4 * x - 3;
}

double derivative_f1(double x)
{
    return 3 * x * x + 4;
}

double f2(double x)
{
    return exp(x) - x - 2;
}

double derivative_f2(double x)
{
    return exp(x) - 1;
}

double f3(double x)
{
    return pow(x, 3) + 3 * x + 2.2;
}

double derivative_f3(double x)
{
    return 3 * x * x + 3;
}

int main(void)
{
    std::cout.setf(std::iostream::fixed);

    std::cout.precision(3);
    std::cout << "dichotomy f1(): " << dichotomy(f1, 0, 1) << '\n';
    std::cout << "chord f1(): " << chord(f1, 0, 1) << '\n';
    std::cout << "newton f1(): " << newton(f1, derivative_f1, 0, 1) << '\n';

    std::cout << '\n';

    std::cout.precision(4);
    std::cout << "dichotomy f2(): " << dichotomy(f2, -2, -1, 0.0001) << '\n';
    std::cout << "chord f2(): " << chord(f2, -2, -1, 0.0001) << '\n';
    std::cout << "newton f2(): " << newton(f2, derivative_f2, -2, -1, 0.0001) << '\n';

    std::cout << '\n';

    std::cout.precision(3);
    std::cout << "dichotomy f3(): " << dichotomy(f3, -1, 0) << '\n';
    std::cout << "chord f3(): " << chord(f3, -1, 0) << '\n';
    std::cout << "newton f3(): " << newton(f3, derivative_f3, -1, 0) << '\n';
    return 0;
}
