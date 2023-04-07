#include <integration.hpp>

double trapezoidal_rule(std::function<double(double)> f, double a, double b, unsigned long n, double eps)
{
    double sq[2] = { 0 };
    int pos;
    double delta = 1;

    for (pos = 0; delta > eps; n *= 2, pos ^= 1) {
        double h = (b - a) / n;
        double I = (f(a) + f(b)) / 2;
        for (decltype(n) i = 1; i < n; ++i) {
            double x = a + i * h;
            I += f(x);
        }
        I *= h;
        sq[pos] = I;
        delta = fabs(sq[1] - sq[0]);
    }

    return sq[pos];
}
