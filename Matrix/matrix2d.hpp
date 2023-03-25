#pragma once

#include <vector>

typedef std::vector<std::vector<double>> Matrix2d;

Matrix2d operator*(const Matrix2d& A, const Matrix2d& B)
{
    if (A.size() == 0 || B.size() == 0 || A[0].size() != B.size()) {
        return {};
    }
    Matrix2d res;
    for (size_t i = 0; i < A.size(); ++i) {
        res.push_back(std::vector<double>());
        for (size_t j = 0; j < B.at(0).size(); ++j) {
            res[i].push_back(0);
            for (size_t k = 0; k < A[0].size(); ++k) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

Matrix2d operator-(const Matrix2d& A, const Matrix2d& B)
{
    if (A.size() != B.size()) {
        return {};
    }
    Matrix2d res;
    for (size_t i = 0; i < A.size(); ++i) {
        res.push_back({});
        for (size_t j = 0; j < A[0].size(); ++j) {
            res[i].push_back(0);
            res[i][j] = A[i][j] - B[i][j];
        }
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, const Matrix2d& m)
{
    for (const auto& row : m) {
        for (const auto& element : row) {
            os << element << " ";
        }
        os << '\n';
    }
    return os;
}

void get_matrix(char* path, Matrix2d& ex);

std::vector<double> gauss(Matrix2d& matrix);

std::vector<double> fpi(Matrix2d& matrix, double eps = 1e-6);
std::pair<bool, size_t> is_fpi_applicable(Matrix2d& matrix);
