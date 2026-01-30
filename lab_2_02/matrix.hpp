#pragma once
#include <iostream>

namespace saturnLib {
    class Matrix {
    private:
        double** matrix_;
        int rows_;
        int cols_;

    public:
        //конструкторы
        Matrix();
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);

        //оператор присваивания
        Matrix& operator=(Matrix other);

        //деструктор
        ~Matrix();

        //геттеры
        int getRows() const { return rows_; }
        int getCols() const { return cols_; }
        double at(int row, int col) const;

        //сеттеры
        void setValue(int row, int col, double value);

        //операторы
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;

        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const { return !(*this == other); }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);

        //методы
        void transpose();
        double determinant() const;
    };
    std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    std::istream& operator>>(std::istream& is, Matrix& matrix);
}
