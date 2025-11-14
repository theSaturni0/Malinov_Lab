#include "array_func.hpp"
#include "base_func.hpp"
#include <fstream>
#include <iostream>


using namespace saturnLib;
using namespace std;

namespace saturnLib {
    vector<int> saturnLib::inputData(const std::string& file) {
        ifstream inputFile(file);

        if (!inputFile.is_open()) {
            cout << "err input";
            return vector<int>();
        }

        string line;
        getline(inputFile, line);
        inputFile.close();

        vector<string> numArray;
        numArray = numString(line);
        if (!validNumString(numArray, validWholeNum) || numArray.size() > 1000) {
            return vector<int>();
        }
        return numStringIntConvert(numArray);
    }

    vector<int> saturnLib::primeNumbersArray(const vector<int>& arr) {
        vector<int> primeArray;
        for (int i = 0; i < arr.size(); i++) {
            if (isPrime(arr[i])) primeArray.push_back(arr[i]);
        }
        return primeArray;
    }

    void saturnLib::calculateSums(const std::vector<int>& arr, int& evenSum, int& oddSum) {
        evenSum = 0;
        oddSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                evenSum += arr[i];
            } else {
                oddSum += arr[i];
            }   
        }
    }

    void saturnLib::reverseArray(vector<int>& arr) {
        vector<int> temp(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            temp[arr.size()-1-i] = arr[i];
        }
        arr = temp;
    }

    void saturnLib::outputData(const std::string& filename, vector<int>& arr, int evenSum, int oddSum) {
        std::ofstream outputFile(filename);

        if (!outputFile.is_open()) {
            cout << "err output";
            return;
        }

        outputFile << "Простые числа: ";
        vector<int> primeNum = primeNumbersArray(arr);
        for (int i = 0; i < primeNum.size(); i++) {
            outputFile << primeNum[i];
            if (i != primeNum.size()-1) outputFile << " ";
        }
        outputFile << std::endl;

        calculateSums(arr, evenSum, oddSum);

        outputFile << "Сумма чётных чисел: " << evenSum << std::endl;
        outputFile << "Сумма нечётных чисел: " << oddSum << std::endl;

        reverseArray(arr);
        
        outputFile << "Массив после реверса: ";
        for (int i = 0; i < arr.size(); i++) {
            outputFile << arr[i];
            if (i != arr.size()-1) outputFile << " ";
        }
        
        outputFile.close();
    }
}