#include <interpolation.hpp>

double newtonInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi)
{
    size_t n = x.size();
    std::vector<double> d;

    for (size_t i = 0; i < n; ++i)
        d.push_back(y[i]);

    for (size_t j = 1; j < n; ++j) {
        for (size_t i = n - 1; i >= j; --i) {
            d[i] = (d[i] - d[i - 1]) / (x[i] - x[i - j]);
        }
    }

    double result = d[n - 1]; // значение интерполяционного многочлена в точке xi
    for (long i = n - 2; i >= 0; --i) {
        result = d[i] + (xi - x[i]) * result;
    }

    return result;
}
