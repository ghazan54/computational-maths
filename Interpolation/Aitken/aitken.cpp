#include <interpolation.hpp>

double aitkenInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi)
{
    int n = x.size();
    std::vector<double> delta(n), P(n);
    delta = y;
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            delta[j] = ((xi - x[j - i]) * delta[j] - (xi - x[j]) * delta[j - 1]) / (x[j] - x[j - i]);
        }
    }
    P = delta;
    return P[n - 1];
}
