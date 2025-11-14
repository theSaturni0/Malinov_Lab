#pragma once

#include <string>
#include <vector>

namespace saturnLib {
    std::vector<int> inputData(const std::string& filename);

    std::vector<int> primeNumbersArray(const std::vector<int>& arr);
    void calculateSums(const std::vector<int>& arr, int& evenSum, int& oddSum);
    void reverseArray(std::vector<int>& arr);

    void outputData(const std::string& filename, std::vector<int>& arr, int evenSum, int oddSum);
}