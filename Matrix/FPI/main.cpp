#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <matrix2d.hpp>

void get_matrix(char* path, Matrix2d& ex)
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        file.open(path);
        int c;
        file >> c;
        for (int i = 0; i < c; ++i) {
            std::vector<double> s;
            for (int j = 0; j < c + 1; ++j) {
                double t;
                file >> t;
                s.push_back(t);
            }
            ex.push_back(s);
        }
        file.close();
    } catch (std::ifstream::failure& e) {
        std::cerr << "The equation is incorrectly set\n";
        exit(EXIT_FAILURE);
    }
}

std::pair<bool, size_t> is_fpi_applicable(Matrix2d& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++) {
        double sum = 0.0;
        for (size_t j = 0; j < matrix.size(); j++) {
            if (i != j) {
                sum += fabs(matrix[i][j]);
            }
        }
        if (fabs(matrix[i][i]) <= sum) {
            return { false, i };
        }
    }
    return { true, 0 };
}

int run_fpi(char* path)
{
    Matrix2d matrix;
    get_matrix(path, matrix);

    std::cout << "Your matrix:\n"
              << matrix << '\n';

    auto retp = is_fpi_applicable(matrix);
    if (!retp.first) {
        std::cerr << "Not applicable for FPI method :: error line: " << retp.second << '\n';
        exit(1);
    }

    std::vector<double> result = fpi(matrix);
    unsigned c = 1;
    std::cout << "\nResult:\n";
    for (const auto& i : result)
        std::cout << 'x' << c++ << " = " << i << ";  ";
    std::cout << '\n';

    return 0;
}

void divVstr(std::vector<double>& v, double x)
{
    for (auto& i : v)
        i /= x;
}

std::vector<double> fpi(Matrix2d& matrix, double eps)
{
    Matrix2d C, B;
    for (size_t i = 0; i < matrix.size(); ++i) {
        C.push_back({});
        for (size_t j = 0; j < matrix[0].size() - 1; ++j) {
            C[i].push_back(matrix[i][j]);
        }
    }
    for (size_t i = 0; i < matrix.size(); ++i)
        B.push_back({ matrix[i][matrix[0].size() - 1] });

    for (size_t i = 0; i < C.size(); ++i) {
        double x = C[i][i];
        C[i][i] = 0;
        divVstr(C[i], x);
        B[i][0] /= x;
    }

    Matrix2d X;
    for (size_t i = 0; i < B.size(); ++i)
        X.push_back({ 0 });

    bool cont = true;
    while (cont) {
        Matrix2d X_prev = X;
        X = B - (C * X);
        cont = false;
        for (size_t i = 0; i < X.size(); ++i) {
            if (fabs(X[i][0] - X_prev[i][0]) > eps) {
                cont = true;
                break;
            }
        }
    }

    std::vector<double> res;
    for (size_t i = 0; i < X.size(); ++i)
        res.push_back(X[i][0]);

    return res;
}

int main(int argc, char** argv)
{
    return argc > 1 ? run_fpi(argv[1]) : EXIT_FAILURE;
}
