#include "matrix.hpp"
#include <algorithm>

namespace saturnLib {
    Matrix::Matrix() : matrix_(nullptr), rows_(0), cols_(0) {}
    Matrix::Matrix(const int rows, const int cols) : Matrix() {
        if (rows <= 0 || cols <= 0) { return; }

        rows_ = rows;
        cols_ = cols;

        matrix_ = new double*[rows_];
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_];
            for (int j = 0; j < cols_; j++) {
                matrix_[i][j] = 0.0;
            }
        }
    }
    Matrix::Matrix(const Matrix& other) : Matrix() {
        if (other.matrix_ == nullptr) { return; }
        if (other.rows_ <= 0 || other.cols_ <= 0) { return; }
        rows_ = other.rows_;
        cols_ = other.cols_;

        matrix_ = new double*[rows_];
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_];
            for (int j = 0; j < cols_; j++) {
                matrix_[i][j] = other.matrix_[i][j];
            }
        }
    }

    //оператор присваивания
    Matrix& Matrix::operator=(Matrix other) {
        if (this == &other) { return *this; }
        if (matrix_ != nullptr) {
            for (int i = 0; i < rows_; i++) {
                delete[] matrix_[i];
            }
            delete[] matrix_;
            matrix_ = nullptr;
        }
        std::swap(matrix_, other.matrix_);
        std::swap(rows_, other.rows_);
        std::swap(cols_, other.cols_);

        return *this;
    }

    //деструктор
    Matrix::~Matrix() {
        if (matrix_ == nullptr) { return; }

        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;
        matrix_ = nullptr;
    }

    double Matrix::at(int const row, int const col) const {
        if (matrix_ == nullptr) { return 0.0; }
        if (row < 0 || col < 0 || row >= rows_ || col >= cols_) { return 0.0; }
        return matrix_[row][col];
    }

    //сеттеры
    void Matrix::setValue(const int row, const int col, const double value) {
        if (matrix_ == nullptr) { return; }
        if (row < 0 || col < 0 || row >= rows_ || col >= cols_) { return; }
        matrix_[row][col] = value;
    }

    //операторы
    Matrix Matrix::operator+(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) { return Matrix(); }

        Matrix Result(rows_, cols_);
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                Result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
            }
        }

        return Result;
    }

    Matrix Matrix::operator-(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) { return Matrix(); }

        Matrix Result(rows_, cols_);
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                Result.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
            }
        }

        return Result;
    }

    Matrix Matrix::operator*(const Matrix& other) const {
        if (cols_ != other.rows_) { return Matrix(); }
        Matrix Result(rows_, other.cols_);
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                double tmp_result = 0;
                for (int k = 0; k < cols_; k++) {
                    tmp_result += matrix_[i][k] * other.matrix_[k][j];
                }
                Result.matrix_[i][j] = tmp_result;
            }
        }
        return Result;
    }

    bool Matrix::operator==(const Matrix& other) const {
        if (rows_ != other.rows_) { return false; }
        if (cols_ != other.cols_) { return false; }
        const double eps = 1e-10;
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > eps) {
                    return false;
                }
            }
        }
        return true;
    }

    void Matrix::transpose() {
        if (matrix_ == nullptr) { return; }
        auto Tmp = Matrix(cols_, rows_);
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                Tmp.matrix_[j][i] = matrix_[i][j];
            }
        }
        std::swap(matrix_, Tmp.matrix_);
        std::swap(rows_, Tmp.rows_);
        std::swap(cols_, Tmp.cols_);
    }

    double Matrix::determinant() const {
        if (matrix_ == nullptr) { return 0.0; }
        if (rows_ != cols_) { return 0.0; }

        auto tmp_matrix = new double*[rows_];
        for (int i = 0; i < rows_; i++) {
            tmp_matrix[i] = new double[cols_];
            for (int j = 0; j < cols_; j++) {
                tmp_matrix[i][j] = matrix_[i][j];
            }
        }

        double det = 1;

        for (int i = 0; i < rows_; i++) {
            int pivot = i;
            for (int j = i + 1; j < cols_; j++) {
                if (std::abs(tmp_matrix[j][i]) > std::abs(tmp_matrix[pivot][i])) {
                    pivot = j;
                }
            }

            if (std::abs(tmp_matrix[pivot][i]) < 1e-10) {
                for (int j = 0; j < rows_; j++) {
                    delete[] tmp_matrix[j];
                }
                delete[] tmp_matrix;
                tmp_matrix = nullptr;
                return 0;
            }

            if (pivot != i) {
                std::swap(tmp_matrix[i], tmp_matrix[pivot]);
                det *= -1;
            }

            for (int j = i + 1; j < rows_; j++) {
                double factor = tmp_matrix[j][i] / tmp_matrix[i][i];
                for (int k = i + 1; k < cols_; k++) {
                    tmp_matrix[j][k] -= factor * tmp_matrix[i][k];
                }
            }

            det *= tmp_matrix[i][i];
        }
        for (int i = 0; i < rows_; i++) {
            delete[] tmp_matrix[i];
        }
        delete[] tmp_matrix;
        tmp_matrix = nullptr;

        return det;
    }
    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        if (matrix.matrix_ == nullptr) {
            os << "Empty Matrix\n";
            return os;
        }

        os << "Matrix " << matrix.rows_ << "x" << matrix.cols_ << ":\n";
        for (int i = 0; i < matrix.rows_; i++) {
            os << "[ ";
            for (int j = 0; j < matrix.cols_; j++) {
                os << matrix.matrix_[i][j];
                if (j < matrix.cols_ - 1) {
                    os << ", ";
                }
            }
            os << " ]\n";
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Matrix& matrix) {
        if (matrix.matrix_ != nullptr) {
            for (int i = 0; i < matrix.rows_; i++) {
                delete[] matrix.matrix_[i];
            }
            delete[] matrix.matrix_;
            matrix.matrix_ = nullptr;
        }

        int rows, cols;
        is >> rows >> cols;

        if (rows <= 0 || cols <= 0) {
            matrix.rows_ = 0;
            matrix.cols_ = 0;
            matrix.matrix_ = nullptr;
            return is;
        }

        matrix.rows_ = rows;
        matrix.cols_ = cols;

        matrix.matrix_ = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix.matrix_[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                is >> matrix.matrix_[i][j];
            }
        }

        return is;
    }
}