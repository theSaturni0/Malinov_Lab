#include "base_func.hpp"
#include <iostream>
#include <cmath>

using namespace saturnLib;
using namespace std;

namespace saturnLib {
    bool saturnLib::isPrime(int number) {
        if (number <= 1) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;
        
        for (int i = 3; i <= sqrt(number); i += 2) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool saturnLib::validWholeNum(string num) {
        if (num.empty()) return false;
        
        int start = 0;

        if (num[0] == '0') return false;

        for (int i = start; i < num.length(); i++) {  
            if (num[i] < '0' || num[i] > '9') return false;
        }
        
        return true;
    }

    bool saturnLib::validNaturalNum(string num) {
        if (num.empty()) return false;
        
        int start = 0;

        if (num[0] == '0' && num.length() != 1) return false;

        for (int i = start; i < num.length(); i++) {  
            if (num[i] < '0' || num[i] > '9') return false;
        }
        
        return true;
    }

    bool saturnLib::validIntNum(string num) {
        if (num.empty()) return false;
        
        int start = 0;

        if (num[0] == '0' && num.length() != 1) return false;
        
        if (num[0] == '-') {
            if (num.length() == 1) return false;
            start = 1;
        }
        
        for (int i = start; i < num.length(); i++) {  
            if (num[i] < '0' || num[i] > '9') return false;
        }
        
        return true;
    }

    bool saturnLib::validFloatNum(string num) {
        if (num.empty()) return false;
        
        int start = 0;
        bool decimal = false;
        
        if (num[0] == '-') {
            if (num.length() == 1) return false;
            start = 1;
        }

        if (num[0] == '0' && num.length() != 1) return false;

        if (num[start] == '.' || num[num.length()-1] == '.') return false;
        
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

    std::vector<std::string> saturnLib::numString(std::string stringInput) {
        vector<string> vectorNumbers;
        string currentNum = "";
        for (char c : stringInput) {
            if (c == ' ') {
                if (!currentNum.empty()) {
                    vectorNumbers.push_back(currentNum);
                    currentNum = "";
                }
            } else {
                currentNum += c;
            }
        }
        if (!currentNum.empty()) {
            vectorNumbers.push_back(currentNum);
        }

        return vectorNumbers;
    }

    std::vector<int> saturnLib::numStringIntConvert(std::vector<std::string> stringArray) {
        vector<int> vectorNumbers;
        for (int i = 0; i < stringArray.size(); i++) {
            vectorNumbers.push_back(stoi(stringArray[i]));
        }
        return vectorNumbers;
    }

    std::vector<float> saturnLib::numStringFloatConvert(std::vector<std::string> stringArray) {
        vector<float> vectorNumbers;
        for (int i = 0; i < stringArray.size(); i++) {
            vectorNumbers.push_back(stof(stringArray[i]));
        }
        return vectorNumbers;
    }

    bool saturnLib::validNumString(std::vector<std::string> vectorNumbers, bool (*type)(std::string num)) {
        for (int i = 0; i < vectorNumbers.size(); i++) {
            if (!type(vectorNumbers[i])) {
                return false;
            }
        }
        return true;
    }
}

