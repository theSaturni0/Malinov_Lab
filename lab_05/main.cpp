#include "matrix_func.hpp"
#include <iostream>

using namespace std;
using namespace mtrxOperations;

int main() {
    int rows1, cols1, rows2, cols2;
    
    while(true) {
        cout << "1 matrix" << endl;
        matrix matrix1 = inputMatrix(rows1, cols1);
        cout << endl;
        
        cout << "2 matrix" << endl;
        matrix matrix2 = inputMatrix(rows2, cols2);
        cout << endl;

        string operationInput;

        while(true) {
            bool valid = 1;

            cout << "1. sum" << endl;
            cout << "2. subtraction" << endl;
            cout << "3. product" << endl;
            cout << "4. determinant" << endl;
            cout << "5. transposition" << endl;
            cout << "6. change matrices" << endl;
            cout << "7. exit" << endl;

            while (true) {
                cout << "enter operation: ";
                getline(cin, operationInput);
                if (validNum(operationInput)) break;
                cout << "invalid" << endl;
            }
            int operation = stoi(operationInput);

            cout << endl;

            switch (operation) {
                case 1: {
                    if ((rows1 != rows2) || (cols1 != cols2)) {
                        cout << "invalid dim";
                        break;
                    } else {
                        matrix sum = sumMatrix(matrix1, matrix2);
                        printMatrix(sum);
                        break;
                    }
                }
                case 2: {
                    if ((rows1 != rows2) || (cols1 != cols2)) {
                        cout << "invalid dim";
                        break;
                    } else {
                        matrix subtraction = subtractionMatrix(matrix1, matrix2);
                        printMatrix(subtraction);
                        break;
                    }
                }
                case 3: {
                    if ((cols1 != rows2)) {
                        cout << "invalid dim";
                        break;
                    } else {
                        matrix product = productMatrix(matrix1, matrix2);
                        printMatrix(product);
                        break;
                    }
                }
                case 4: {
                    if (rows1 != cols1) {
                        cout << "invalid dim1" << endl;
                    } else {
                        double det1 = determinantMatrix(matrix1);
                        cout << det1 << endl;
                    }

                    if (rows2 != cols2) {
                        break;
                    } else {
                        double det2 = determinantMatrix(matrix2);
                        cout << det2;
                        break;
                    }
                }
                case 5: {
                    matrix trans1 = transpositionMatrix(matrix1);
                    matrix trans2 = transpositionMatrix(matrix2);
                    printMatrix(trans1);
                    cout << endl << endl;
                    printMatrix(trans2);
                    break;

                }
                case 6:
                    valid = 0;
                    break;
                case 7:
                    return 0;

                default:
                    cout << "invalid";
                    break;
            }
            cout << endl;
            if (!valid) {
                break;
            }
        }
    }    
}