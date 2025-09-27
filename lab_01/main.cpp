#include <iostream>
#include <cmath>

int main() {

    // целочисленные
    std::cout << "int, size: " << sizeof(int) << " bytes, value range: " << INT_MIN << ", " << INT_MAX << std::endl;
    std::cout << "short, size: " << sizeof(short) << " bytes, value range: " << SHRT_MIN << ", " << SHRT_MAX << std::endl;
    std::cout << "char, size: " << sizeof(char) << " bytes, value range: " << CHAR_MIN << ", " << CHAR_MAX << std::endl;
    std::cout << "long, size: " << sizeof(long) << " bytes, value range: " << LONG_MIN << ", " << LONG_MAX << std::endl;
    std::cout << "long long, size: " << sizeof(long long) << " bytes, value range: " << LLONG_MIN << ", " << LLONG_MAX << std::endl;
    //вещественные
    std::cout << "float, size: " << sizeof(float) << " bytes, value range: " << std::numeric_limits<float>::lowest() << ", " << FLT_MAX << std::endl;
    std::cout << "double, size: " << sizeof(double) << " bytes, value range: " << std::numeric_limits<double>::lowest() << ", " << DBL_MAX << std::endl;
    std::cout << "long double, size: " << sizeof(long double) << " bytes, value range: " << std::numeric_limits<long double>::lowest() << ", " << LDBL_MAX << std::endl;
    //логические
    std::cout << "bool, size: " << sizeof(bool) << " bytes, value range: false, true" << std::endl;
    //unsigned
    std::cout << "unsigned int, size: " << sizeof(unsigned int) << " bytes, value range: 0, " << UINT_MAX << std::endl;
    std::cout << "unsigned short, size: " << sizeof(unsigned short) << " bytes, value range: 0, " << USHRT_MAX << std::endl;
    std::cout << "unsigned char, size: " << sizeof(unsigned char) << " bytes, value range: 0, " << UCHAR_MAX << std::endl;
    std::cout << "unsigned long, size: " << sizeof(unsigned long) << " bytes, value range: 0, " << ULONG_MAX << std::endl;
    std::cout << "unsigned long long, size: " << sizeof(unsigned long long) << " bytes, value range: 0, " << ULLONG_MAX << "\n" << std::endl;

    int Int1 = 5;
    int Int2 = 6;

    std::cout << "Int1 = 5, Int2 = 6, Int1 + Int2 = " << (Int1+Int2) << std::endl;

    short Short1 = 9;
    short Short2 = 32;

    std::cout << "Short1 = 9, Short2 = 32, Short1 - Short2 = " << (Short1-Short2) << std::endl;

    char Char1 = 2;
    char Char2 = 15;
    char Char3 = 3;

    std::cout << "Char1 = 2, Char2 = 15, Char3 = 3, Char1 * Char2 * Char3 = " << (Char1*Char2*Char3) << std::endl;

    long long LLong1 = 1'000'000'000;

    std::cout << "LLong1 = 1 000 000, LLong1 / LLong1 = " << (LLong1/LLong1) << std::endl;

    float Float1 = 2.5;
    float Float2 = 30;

    std::cout << "Float1 = 2.5, FLoat2 = 30, pow(Float1, Float2) = " << (pow(Float1, Float2)) << std::endl;

    double Double1 = 2'485'281'395;

    std::cout << "Double1 = 2 485 281 395, cbrt(Double1) = " << (cbrt(Double1)) << std::endl;

    int a;
    std::cin >> a;

    return 0;

}