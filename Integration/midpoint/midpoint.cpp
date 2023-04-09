#include <integration.hpp>
#include <iostream>

double midpoint_rule(std::function<double(double)> f, double a, double b, unsigned long n0, double eps)
{
    double sq[2] = { 0 };
    double ret;
#pragma omp parallel
    {
        int pos;
        double delta = 1;
        unsigned long n = n0;
        for (pos = 0; delta > eps; n *= 2, pos ^= 1) {
            double h = (b - a) / n;
            sq[pos] = 0;
#pragma omp barrier

#pragma omp for nowait reduction(+ \
                                 : sq[pos])
            for (decltype(n) i = 0; i < n; ++i) {
                double x = a + (i * h) + (h / 2);
                sq[pos] += f(x) * h;
            }

#pragma omp barrier
            delta = fabs(sq[0] - sq[1]);
        }

#pragma omp master
        ret = sq[pos];
    }

    return ret;
}
