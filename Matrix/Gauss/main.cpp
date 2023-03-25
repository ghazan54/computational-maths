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

int run_gauss(char* path)
{
    Matrix2d matrix;
    get_matrix(path, matrix);

    std::cout << "Your matrix:\n"
              << matrix << '\n';

    std::vector<double> result = gauss(matrix);
    unsigned c = 1;
    std::cout << "\nResult:\n";
    for (const auto& i : result)
        std::cout << 'x' << c++ << " = " << i << ";  ";
    std::cout << '\n';

    return 0;
}

std::vector<double> gauss(Matrix2d& matrix)
{
    // прямой ход метода Гаусса
    for (size_t k = 0; k < matrix.size(); k++) {
        // выбор главного элемента
        double max_el = matrix[k][k];
        size_t max_row = k;
        for (size_t i = k + 1; i < matrix.size(); i++) {
            if (fabs(matrix[i][k]) > fabs(max_el)) {
                max_el = matrix[i][k];
                max_row = i;
            }
        }
        // перестановка строк
        if (max_row != k) {
            for (size_t j = k; j < matrix.size() + 1; j++) {
                std::swap(matrix[k][j], matrix[max_row][j]);
            }
        }
        // исключение неизвестных
        for (size_t i = k + 1; i < matrix.size(); i++) {
            double factor = matrix[i][k] / matrix[k][k];
            for (size_t j = k + 1; j < matrix.size() + 1; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
            matrix[i][k] = 0.0;
        }
    }
    // обратный ход метода Гаусса
    for (long int k = matrix.size() - 1; k >= 0; k--) {
        matrix[k][matrix.size()] /= matrix[k][k];
        matrix[k][k] = 1.0;
        for (long int i = k - 1; i >= 0; i--) {
            matrix[i][matrix.size()] -= matrix[i][k] * matrix[k][matrix.size()];
            matrix[i][k] = 0.0;
        }
    }
    // Вынос значений x в результирубщий вектор
    std::vector<double> res;
    for (size_t i = 0; i < matrix.size(); ++i)
        res.push_back(matrix[i][matrix.size()]);

    return res;
}

int main(int argc, char** argv)
{
    return argc > 1 ? run_gauss(argv[1]) : EXIT_FAILURE;
}
