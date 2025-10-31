#pragma once

#include <string>

namespace saturnLib {
    struct complexNum {
        float real;
        float imag;
    };

    complexNum* createComplex(float real, float imag);
    void deleteComplex(complexNum* num);

    void printComplex(const complexNum* num);

    complexNum* sumComplex(const complexNum* num1, const complexNum* num2);
    float modulusComplex(const complexNum* num);
}