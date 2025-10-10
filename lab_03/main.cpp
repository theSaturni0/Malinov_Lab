#include <iostream>
#include <cmath>
#include <bitset>

int main() {

    /*
    
    Условные операции: (Некоторое условие, которое возвращает значение типа bool)

        Операции сравнения: (Сравнивает значения)
        == > < >= <= !=

        Логические операции: (Сравнивает значения bool)
        ! && || ^

    Битовые операции: (Работают отдельно с каждым разрядом числа)

    << >> & | ^ ~

    &
    0 0 -> 0
    0 1 -> 0
    1 0 -> 0
    1 1 -> 1

    |
    0 0 -> 0
    0 1 -> 1
    1 0 -> 1
    1 1 -> 1

    ^
    0 0 -> 9
    0 1 -> 1
    1 0 -> 1
    1 1 -> 0


    Битовый сдвиг - умножение/деление на 2**n

    */
    std::cout << "2 * 2**1 = " << (2 << 1) << std::endl;
    std::cout << "2 * 2**2 = " << (2 << 2) << std::endl;
    std::cout << "2 / 2**1 = " << (2 >> 1) << std::endl;
    std::cout << "-2 * 2 = " << (-2 << 1) << std::endl; 
    std::cout << std::endl;
    std::cout << "15 / 2**1 = " << (15 >> 1) << std::endl;
    std::cout << "15 / 2 = " << (15 / 2) << std::endl;
    std::cout << "15f / 2 = " << ((float)15 / 2) << std::endl;
    std::cout << "-15 / 2**1 = " << (-15 >> 1) << std::endl;
    std::cout << "-15 / 2 = " << (-15 / 2) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    // установка i-ого бита

    bool valid = true;

    int x;
    std::cout << "enter x, 0 < x < 10**9" << std::endl;
    std::cin >> x;

    while (x > pow(10,9) || x < 0) {
        std::cout << "invalid value" << std::endl;
        std::cin >> x;
    }

    std::cout << std::endl;
    std::cout << std::bitset<32>(x) << std::endl;

    short bit;
    std::cout << "enter the number of the bit to be set to 1, from 0 to 31" << std::endl;
    std::cin >> bit;

    while (bit > 31 || bit < -1) {
        std::cout << "invalid value" << std::endl;
        std::cin >> x;
    }

    int mask = 1 << bit;

    std::cout << std::endl;
    std::cout << std::bitset<32>(mask) << std::endl;
    std::cout << std::bitset<32>(x|mask) << std::endl;

    return 0;
}