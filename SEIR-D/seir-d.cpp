#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

const double alpha_E = 0.999;
const double alpha_I = 0.999;
const double kappa = 0.042;
const double rho = 0.952;
const double beta = 0.999;
const double mu = 0.0188;
const double c_isol = 0;
const double E0 = 99;
const double R0 = 24;

const double N0 = 2798170.0;
const double S0 = N0 - E0 - R0;
const double I0 = 0.0;
const double D0 = 0.0;

const double _gamma = 0.001;

double c(double t)
{
    double a = t < 70 ? sin(M_PI * (t - 35) / 35) : 0;
    return std::max(0.0, std::min(2.0, 1 + c_isol * ((1 - 2 / 5) * a)));
}

std::vector<double> func(double t, std::vector<double> Y)
{
    double S = Y[0];
    double E = Y[1];
    double I = Y[2];
    double R = Y[3];
    double D = Y[4];
    double N = S + E + I + R + D;
    double c_t = c(t);
    double dSdt = -c_t * (alpha_I * S * I / N + alpha_E * S * E / N) + _gamma * R;
    double dEdt = c_t * (alpha_I * S * I / N + alpha_E * S * E / N) - (kappa + rho) * E;
    double dIdt = kappa * E - beta * I - mu * I;
    double dRdt = beta * I + rho * E - _gamma * R;
    double dDdt = mu * I;
    std::vector<double> res = { dSdt, dEdt, dIdt, dRdt, dDdt };
    return res;
}

std::vector<std::pair<double, std::vector<double>>> euler_method(std::vector<double> (*f)(double, std::vector<double>), double t_0, std::vector<double> Y_0, double h, double t_max)
{
    double t = t_0;
    std::vector<double> Y = Y_0;
    std::vector<std::pair<double, std::vector<double>>> solution = { { t, Y } };
    while (t < t_max) {
        for (size_t i = 0; i < Y.size(); ++i) {
            Y[i] += h * f(t, Y)[i];
        }
        t = t + h;
        solution.push_back({ t, Y });
    }
    return solution;
}

int main(void)
{
    double t_0 = 0.0;
    double t_max = 90.0;
    double h = 0.1;
    std::vector<double> Y_0 = { S0, E0, I0, R0, D0 };
    std::vector<std::pair<double, std::vector<double>>> solution = euler_method(func, t_0, Y_0, h, t_max);

    std::cout << "Time (days)\tSusceptible\tExposed\tInfected\tRecovered\tDead" << '\n';
    for (auto& sol : solution) {
        double t = sol.first;
        std::vector<double> Y = sol.second;
        std::cout << t << "\t" << Y[0] << "\t" << Y[1] << "\t" << Y[2] << "\t" << Y[3] << "\t" << Y[4] << '\n';
    }

    std::ofstream db("data.dat");
    db << "# Time (days)\tInfected" << '\n';
    for (auto& sol : solution) {
        double t = sol.first;
        std::vector<double> Y = sol.second;
        db << t << "\t" << Y[2] << "\t" << '\n';
    }

    return 0;
}
