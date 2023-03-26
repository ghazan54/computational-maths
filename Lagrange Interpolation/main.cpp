#include <fstream>
#include <iostream>
#include <vector>

double lagrangeInterpolation(std::vector<double>& x, std::vector<double>& y, double xi)
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

void pointsTofile(std::vector<double>& x, std::vector<double>& y, double res, double xi)
{
    std::ofstream f1("points.dat");
    std::ofstream f2("result.dat");

    f2 << xi << ' ' << res << '\n';

    for (size_t i = 0; i < x.size(); ++i)
        f1 << x[i] << ' ' << y[i] << '\n';
}

int main(void)
{
    std::vector<double> x = { 1, 2, 3, 4 };
    std::vector<double> y = { 1, 4, 9, 16 };
    double xi = 2.5;
    double result = lagrangeInterpolation(x, y, xi);
    std::cout << result << '\n';
    pointsTofile(x, y, result, xi);
    return 0;
}
