#include "array_func.hpp"
#include <iostream>

using namespace std;
using namespace saturnLib;

int main() {
    std::vector<int> numbersArray = inputData("input.txt");    
    int evenSum = 0;
    int oddSum = 0;
    outputData("output.txt", numbersArray, evenSum, oddSum);
    
    return 0;
}