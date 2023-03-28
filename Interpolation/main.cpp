#include <interpolation.hpp>

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
    std::cout << "Lagrange: " << result << '\n';

    result = aitkenInterpolation(x, y, xi);
    std::cout << "Aitken: " << result << '\n';

    pointsTofile(x, y, result, xi);

    return 0;
}