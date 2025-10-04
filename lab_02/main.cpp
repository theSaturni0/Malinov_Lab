#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    /*

    ---

    Стандартные арифметические операции:

    Сумма:
    a + b
    a +=

    Вычитание:
    a - b
    a -=

    Умножение:
    a * b
    a *=

    Деление: (целочисленные и вещественные)
    a / b
    a /=

    Остаток от деления: (только целые числа)
    a % b
    a %=

    ---

    Префиксный инкремент:
    ++a
    Постфиксный инкремент:
    a++

    Префиксный декремент:
    --a
    Постфиксный декремент:
    a--

    ---

    Приоритет операторов: 
    
    ()
    ++ -- (Префиксный)
    * / %
    + -
    ++ -- (Постфиксный) (Почти)

    ---
    
    */

    int Int1 = 5;
    int Int2 = 6;

    std::cout << "5 + 6 = " << (Int1+Int2) << std::endl;

    float Float1 = 2.7;
    float Float2 = 8.45;

    std::cout << "2.7 * 8.45 = " << (Float1*Float2) << std::endl;

    int Div_i1 = 10;
    int Div_i2 = 3;

    std::cout << "int: \n10 / 3 = " << (Div_i1/Div_i2) << std::endl;

    float Div_f1 = 10;
    float Div_f2 = 3;

    std::cout << "float: \n10 / 3 = " << (Div_f1/Div_f2) << std::endl;

    int Int3 = 7;
    int Int4 = 8;
    int Int5 = 12;

    std::cout << "7 + 8 * 3 = " << (Int3+Int4*Int5) << std::endl;
    std::cout << "(7 + 8) * 3 = " << ((Int3+Int4)*Int5) << std::endl;

    double Double1 = 0.1;
    double Double2 = 0.2;
    
    std::cout << "0.1 + 0.2 = " << std::setprecision(20) << (Double1 + Double2) << std::endl;
    std::cout << "0.1 + 0.2 = " << std::setprecision(5) << (Double1 + Double2) << std::endl;

    std::cout << "\n\n---\n" << std::endl;

    // вычисление объема пирамиды

    short space;
    short height;
    bool valid = true;
    
    double volume;

    std::cout << "\nCalculating volume of the pyramid" << std::endl;

    // ввод площади

    std::cout << "\nEnter the base area of the pyramid (0<S<100):" << std::endl;
    std::cin >> space;

    if(space > 0 && space < 100) {
        
    }

    else {
        valid = false;
    }

    // ввод высоты

    std::cout << "\nEnter the height of the pyramid (0<h<100):" << std::endl;
    std::cin >> height;

    if(height > 0 && height < 100) {

    }

    else {
        valid = false;
    }

    // вычисление объема

    if(valid) {
        volume = (space*height)/3.0;
        std::cout << std::setprecision(5) << "\nVolume of the pyramid is equal to " << volume << std::endl;
    }

    else {
        std::cout << "\nInvalid value" << std::endl;
    }

    int a;
    std::cin >> a;

    return 0;

}