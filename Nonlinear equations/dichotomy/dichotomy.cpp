#include <nlequations.hpp>

double dichotomy(double (*f)(double), double a, double b, double eps)
{
    double c = (a + b) / 2;
    long i = 1;
    while (fabs(b - a) > eps) {
        if (f(c) * f(b) > 0)
            b = c;
        else
            a = c;
        c = (a + b) / 2;
        ++i;
    }
    return c;
}
