#include <interpolation.hpp>

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi)
{
    double result = 0.0;

    for (int i = 0; i < static_cast<int>(x.size()); ++i) {
        double term = y[i];
        for (int j = 0; j < static_cast<int>(x.size()); ++j) {
            if (i != j) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}
