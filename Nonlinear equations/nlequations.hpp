#pragma once

#include <cmath>

double dichotomy(double (*f)(double), double a, double b, double E = 0.001);
double chord(double (*f)(double), double a, double b, double E = 0.001);
double newton(double (*f)(double), double (*f_derivative)(double), double a, double b, double E = 0.001);
