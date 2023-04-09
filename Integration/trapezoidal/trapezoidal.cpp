#include <integration.hpp>

double trapezoidal_rule(std::function<double(double)> f, double a, double b, unsigned long n0, double eps)
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
            double I = (f(a) + f(b)) / 2;
            sq[pos] = 0;
#pragma omp barrier
#pragma omp for nowait
            for (decltype(n) i = 1; i < n; ++i) {
                double x = a + i * h;
                I += f(x);
            }
#pragma omp atomic
            sq[pos] += I * h;
#pragma omp barrier
            delta = fabs(sq[1] - sq[0]);
        }
#pragma omp master
        ret = sq[pos];
    }

    return ret;
}
