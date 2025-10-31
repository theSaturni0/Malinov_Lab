#include "complexNum_func.hpp"
#include "base_func.hpp"
#include <iostream>
#include <cmath>

using namespace saturnLib;
using namespace std;

complexNum* saturnLib::createComplex(float real, float imag) {
    complexNum* newNum = new complexNum;
    newNum->real = real;
    newNum->imag = imag;
    return newNum;
}

void saturnLib::deleteComplex(complexNum* num) {
    delete num;
}

//

void saturnLib::printComplex(const complexNum* num) {    
    if (num->imag >= 0) {
        cout << num->real << " + " << num->imag << "i" << endl;
    } else if (num->imag !=0) {
        cout << num->real << " - " << -num->imag << "i" << endl;
    } else {
        cout << num->real;
    }
}

//

complexNum* saturnLib::sumComplex(const complexNum* num1, const complexNum* num2) {
    complexNum* result = new complexNum;
    result->real = num1->real + num2->real;
    result->imag = num1->imag + num2->imag;
    return result;
}

float saturnLib::modulusComplex(const complexNum* num) {
    return sqrt(num->real * num->real + num->imag * num->imag);
}