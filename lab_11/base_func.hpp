#pragma once

#include <string>
#include <vector>

namespace saturnLib {
    bool isPrime(int number);

    std::vector<std::string> numString(std::string num);

    bool validNumString(std::vector<std::string> vectorNumbers, bool (*type)(std::string num));
    bool validNaturalNum(std::string num);
    bool validWholeNum(std::string num);
    bool validIntNum(std::string num);
    bool validFloatNum(std::string num);

    std::vector<int> numStringIntConvert(std::vector<std::string> stringArray);
    std::vector<float> numStringFloatConvert(std::vector<std::string> stringArray);
}