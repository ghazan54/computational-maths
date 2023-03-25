#include <nlequations.hpp>

double newton(double (*f)(double), double (*f_derivative)(double), double a, double b, double eps)
{
    double prev = a;
    while (fabs(b - prev) > eps) {
        prev = b;
        b = prev - f(prev) / f_derivative(prev);
    }
    return b;
}
