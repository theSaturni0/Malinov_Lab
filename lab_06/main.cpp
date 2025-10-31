#include "base_func.hpp"
#include "complexNum_func.hpp"
#include <iostream>

using namespace std;
using namespace saturnLib;

int main() {
    complexNum* num1 = nullptr;

    string input1 = "3 4";
    std::vector<std::string> input1Num = numString(input1);
    if (validNumString(input1Num)) {
        float real1 = stod(input1Num[0]);
        float imag1 = stod(input1Num[1]);
        num1 = createComplex(real1, imag1);
    } else {
        cout << "invalid";
        deleteComplex(num1);
    }

    complexNum* num2 = nullptr;

    string input2 = "1.5 -2.5";
    std::vector<std::string> input2Num = numString(input2);
    if (validNumString(input2Num)) {
        float real2 = stod(input2Num[0]);
        float imag2 = stod(input2Num[1]);
        num2 = createComplex(real2, imag2);
    } else {
        cout << "invalid";
        deleteComplex(num2);
    }

    complexNum* num3 = nullptr;

    string input3 = "-2 0";
    std::vector<std::string> input3Num = numString(input3);
    if (validNumString(input3Num)) {
        float real3 = stod(input3Num[0]);
        float imag3 = stod(input3Num[1]);
        num3 = createComplex(real3, imag3);
    } else {
        cout << "invalid";
        deleteComplex(num3);
    }

    complexNum* num4 = nullptr;
    
    string input4 = "error";
    std::vector<std::string> input4Num = numString(input4);
    if (validNumString(input4Num)) {
        float real4 = stod(input4Num[0]);
        float imag4 = stod(input4Num[1]);
        num4 = createComplex(real4, imag4);
    } else {
        cout << "invalid";
        deleteComplex(num4);
    }
    
    cout << "Numbers:" << endl;
    cout << "num1 = "; printComplex(num1);
    cout << "num2 = "; printComplex(num2);
    cout << "num3 = "; printComplex(num3);
    cout << endl;
    
    cout << "Мodulus:" << endl;
    cout << "|num1| = " << modulusComplex(num1) << endl;
    cout << "|num2| = " << modulusComplex(num2) << endl;
    cout << "|num3| = " << modulusComplex(num3) << endl;
    cout << endl;
    
    cout << "Sum:" << endl;
    complexNum* sum1 = sumComplex(num1, num2);
    cout << "num1 + num2 = "; printComplex(sum1);
    complexNum* sum2 = sumComplex(sum1, num3);
    cout << "(num1 + num2) + num3 = "; printComplex(sum2);
    cout << endl;

    deleteComplex(num1);
    deleteComplex(num2);
    deleteComplex(num3);
    deleteComplex(num4);
    deleteComplex(sum1);
    deleteComplex(sum2);
}