#pragma once

#include <cmath>
#include <functional>

double euler(std::function<double(double, double)> f, double x0, double x1, double y0, double eps = 10e-6, double h = 0.1);

// version RK4
double runge_kutta(std::function<double(double, double)> f, double x0, double x1, double y0, double eps = 10e-6, double h = 0.1);
