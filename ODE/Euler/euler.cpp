#include <iostream>
#include <ode.hpp>

double euler(std::function<double(double, double)> f, double x0, double x1, double y0, double eps, double h)
{
    double yi = y0;
    double y1, y2;

    while (x0 < x1) {
        y1 = yi + h * f(x0, yi);
        y2 = yi + h / 2.0 * (f(x0, yi) + f(x0 + h, y1)); // Cauchy–Euler
        double err = fabs(y2 - y1);
        if (err < eps) { // LEC (Local Error Control)
            yi = y2;
            x0 += h;
        } else {
            h /= 2.0;
        }
    }

    return yi;
}
