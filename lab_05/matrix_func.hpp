#ifndef MATRIX_FUNC_HPP
#define MATRIX_FUNC_HPP

#include <vector>
#include <string>

namespace mtrxOperations {
    using matrix = std::vector<std::vector<double>>;

    bool validNum(std::string num);

    matrix inputMatrix(int &rows, int &cols);
    void printMatrix(const matrix &matrix);

    matrix sumMatrix(matrix &matrix1, matrix &matrix2);
    matrix subtractionMatrix(matrix &matrix1, matrix &matrix2);
    matrix productMatrix(matrix &matrix1, matrix &matrix2);
    double determinantMatrix(matrix &matrix1);
    matrix transpositionMatrix(matrix &matrix1);
}

#endif