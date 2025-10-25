#include "matrix_func.hpp"
#include <iostream>

using namespace mtrxOperations;
using namespace std;

bool mtrxOperations::validNum(string num) {
    if (num.empty()) return false;
    
    int start = 0;
    bool decimal = false;
    
    if (num[0] == '-') {
        if (num.length() == 1) return false;
        start = 1;
    }
    
    if (num == "." || num == "-.") {
        return false;
    }
    
    for (int i = start; i < num.length(); i++) {
        if (num[i] == '.') {
            if (decimal) {
                return false;
            }
            decimal = true;
            continue;
        }
        
        if (num[i] < '0' || num[i] > '9') {
            return false;
        }
    }
    
    return true;
}

//

matrix mtrxOperations::inputMatrix(int &rows, int &cols) {
    string rowsInput, colsInput;
    
    while (true) {
        cout << "rows: ";
        getline(cin, rowsInput);
        if (validNum(rowsInput) && stoi(rowsInput) > 0) break;
        cout << "invalid" << endl;
    }
    rows = stoi(rowsInput);

    while (true) {
        cout << "columns: ";
        getline(cin, colsInput);
        if (validNum(colsInput) && stoi(colsInput) > 0) break;
        cout << "invalid" << endl;
    }
    cols = stoi(colsInput);
    
    matrix result(rows, vector<double>(cols));
    
    cout << "enter numbers" << endl;
    
    while (true) {
        bool valid = true;
        
        for (int i = 0; i < rows; i++) {
            string rowInput;
            getline(cin, rowInput);

            vector<string> numberStrings;
            string currentNum = "";
            for (char c : rowInput) {
                if (c == ' ') {
                    if (!currentNum.empty()) {
                        numberStrings.push_back(currentNum);
                        currentNum = "";
                    }
                } else {
                    currentNum += c;
                }
            }
            if (!currentNum.empty()) {
                numberStrings.push_back(currentNum);
            }

            if (numberStrings.size() != cols) {
                valid = false;
                break;
            }

            for (int j = 0; j < cols; j++) {
                if (!validNum(numberStrings[j])) {
                    valid = false;
                    break;
                }
                result[i][j] = stod(numberStrings[j]);
            }
            if (!valid) break;
        }
        
        if (valid) {
            return result;
        } else {
            cout << "invalid" << endl;
        }
    }
}

//

void mtrxOperations::printMatrix(const matrix &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

//

matrix mtrxOperations::sumMatrix(matrix &matrix1, matrix &matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    matrix result(rows, vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

//

matrix mtrxOperations::subtractionMatrix(matrix &matrix1, matrix &matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    matrix result(rows, vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

//

matrix mtrxOperations::productMatrix(matrix &matrix1, matrix &matrix2) {
    int rows = matrix1.size();
    int cols = matrix2[0].size();

    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();

    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    matrix result(rows, vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double tempResult = 0;
            for (int k = 0; k < cols1; k++) {
                tempResult += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = tempResult;
        }
    }
    return result;
}

double mtrxOperations::determinantMatrix(matrix &matrix1) {
    int n = matrix1.size();
    double det = 1;
    
    matrix temp = matrix1;

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(temp[j][i]) > abs(temp[pivot][i])) {
                pivot = j;
            }
        }

        if (abs(temp[pivot][i]) < 1e-10) {
            return 0;
        }
        
        if (pivot != i) {
            swap(temp[i], temp[pivot]);
            det *= -1;
        }
        
        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i + 1; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }

        det *= temp[i][i];
    }
    
    return det;
}

matrix mtrxOperations::transpositionMatrix(matrix &matrix1) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    matrix result(cols, vector<double>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix1[i][j];
        }
    }
    return result;
}