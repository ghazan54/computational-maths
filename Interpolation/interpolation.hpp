#pragma once

#include <fstream>
#include <iostream>
#include <vector>

double lagrangeInterpolation(std::vector<double>& x, std::vector<double>& y, double xi);
double aitkenInterpolation(std::vector<double>& x, std::vector<double>& y, double xi);

void pointsTofile(std::vector<double>& x, std::vector<double>& y, double res, double xi);
