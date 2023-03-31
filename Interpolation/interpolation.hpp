#pragma once

#include <fstream>
#include <iostream>
#include <vector>

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi);
double aitkenInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi);
double newtonInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi);

void pointsTofile(std::vector<double>& x, std::vector<double>& y, double res, double xi);
