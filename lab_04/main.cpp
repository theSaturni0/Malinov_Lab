#include <iostream>
#include <string>

int main() {

    
    int num;
    bool valid;

    std::cout << "input number, 0 < num < 1'000'000'001" << std::endl;

    //

    do {
        valid = 1;
        std::string input = "";
        std::getline(std::cin, input);


        if (input.length() == 0) {

            std::cout << "invalid value" << std::endl;

            valid = 0;
            continue;
        }

        for (int counter = 0; counter < input.length(); counter++) {

            char c = input[counter];
            if (c < '0' || c > '9') {

                std::cout << "invalid value" << std::endl;

                valid = 0;
                break;
            }
        }

        if (!valid) continue;

        num = std::stoi(input);
        if (num < 1 || num > 1'000'000'000) {

            std::cout << "invalid value" << std::endl;

            valid = 0;
            continue;
        }

    } while (!valid);

    //

    int reverse = 0;
    short temp_reverse;
    
    while (num != 0) {
        temp_reverse = num % 10;
        num /= 10;
        if (temp_reverse == 0) {
            temp_reverse = 1;
        }
        reverse = 10 * reverse + temp_reverse;
    }

    std::cout << reverse << std::endl;

    return 0;
}