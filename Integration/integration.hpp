#pragma once

#include <cmath>
#include <functional>

double midpoint_rule(std::function<double(double)> f, double a, double b, unsigned long n = 10000000, double eps = 10e-6);
double trapezoidal_rule(std::function<double(double)> f, double a, double b, unsigned long n = 1000000, double eps = 10e-6);
