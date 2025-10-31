#include "base_func.hpp"
#include <iostream>

using namespace saturnLib;
using namespace std;

bool saturnLib::validNum(string num) {
    if (num.empty()) return false;
    
    int start = 0;
    bool decimal = false;
    
    if (num[0] == '-') {
        if (num.length() == 1) return false;
        start = 1;
    }
    
    if (num == "." || num == "-.") {
        return false;
    }
    
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

bool saturnLib::validNumString(std::vector<std::string> vectorNumbers) {
    for (int i = 0; i < vectorNumbers.size(); i++) {
        if (!validNum(vectorNumbers[i])) {
            return false;
        }
    }
    return true;
}