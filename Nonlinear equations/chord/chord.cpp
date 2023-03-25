#include <nlequations.hpp>

double chord(double (*f)(double), double a, double b, double eps)
{
    double c = (a + b) / 2, c_prev = 0.0;
    long i = 1;
    while (fabs(c - c_prev) > eps) {
        if (f(c) * f(b) > 0)
            b = c;
        else
            a = c;
        c_prev = c;
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        ++i;
    }
    return c;
}
