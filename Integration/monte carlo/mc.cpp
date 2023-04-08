#include <integration.hpp>
#include <iostream>
#include <random>

double monte_carlo(std::function<double(double)> f, double a, double b, unsigned long n, double eps)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(a, b);

    double sq[2] = { 0 };
    int pos;
    double delta = 1;
    for (pos = 0; delta > eps; n *= 2, pos ^= 1) {
        double I = 0.0;
        for (decltype(n) i = 0; i < n; ++i) {
            I += f(static_cast<double>(dis(gen)));
        }
        I *= (b - a) / n;
        sq[pos] = I;
        delta = fabs(sq[1] - sq[0]);
    }

    return sq[pos];
}

double monte_carlo(std::function<double(double, double)> f, std::pair<double, double> w1, std::pair<double, double> w2, unsigned long n, double eps)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis1(w1.first, w1.second);
    std::uniform_real_distribution<double> dis2(w2.first, w2.second);

    double sq[2] = { 0 };
    int pos;
    double delta = 1;
    for (pos = 0; delta > eps; n *= 2, pos ^= 1) {
        double I = 0.0;
        for (decltype(n) i = 0; i < n; ++i) {
            I += f(static_cast<double>(dis1(gen)), static_cast<double>(dis2(gen)));
        }
        I *= (w1.second - w1.first) * (w2.second - w2.first) / n;
        sq[pos] = I;
        delta = fabs(sq[1] - sq[0]);
    }

    return sq[pos];
}
