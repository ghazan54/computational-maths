#pragma once

#include <cmath>
#include <functional>

#define DEFAULT_EPS 10e-3

double midpoint_rule(std::function<double(double)> f, double a, double b, unsigned long n = 10000000, double eps = DEFAULT_EPS);
double trapezoidal_rule(std::function<double(double)> f, double a, double b, unsigned long n = 1000000, double eps = DEFAULT_EPS);
double monte_carlo(std::function<double(double)> f, double a, double b, unsigned long n = 10000000, double eps = DEFAULT_EPS);
double monte_carlo(std::function<double(double, double)> f, std::pair<double, double> w1, std::pair<double, double> w2, unsigned long n = 10000000, double eps = DEFAULT_EPS);
