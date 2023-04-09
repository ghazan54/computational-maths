#include <iostream>
#include <ode.hpp>

double runge_kutta(std::function<double(double, double)> f, double x0, double x1, double y0, double eps, double h)
{
    double yi = y0;
    double y1, y2;

    while (x0 < x1) {
        double k1 = f(x0, yi);
        double k2 = f(x0 + h / 2, yi + h * k1 / 2.0);
        double k3 = f(x0 + h / 2, yi + h * k2 / 2.0);
        double k4 = f(x0 + h, yi + h * k3);
        y1 = yi + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        double k1_half = f(x0, yi);
        double k2_half = f(x0 + h / 4, yi + h / 4 * k1_half);
        double k3_half = f(x0 + h / 4, yi + h / 4 * k2_half);
        double k4_half = f(x0 + h / 2, yi + h / 2 * k3_half);
        y2 = yi + h / 2 * (k1_half + 2 * k2_half + 2 * k3_half + k4_half) / 6;

        double err = fabs((y1 - y2) / 15.0); // for RK4
        if (err < eps) { // LEC
            yi = y1;
            x0 += h;
        } else {
            h /= 2.0;
        }
    }

    return yi;
}
