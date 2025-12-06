#include "sort_func.hpp"
#include "base_func.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace saturnLib;
using namespace std;

int main() {
    string line;
    vector<string> stringArr;
    vector<float> arr;

    line = "5 5 5 12 2 4535 2";

    stringArr = numString(line);
    if (!validNumString(stringArr, validFloatNum)) {
        cout << "Invalid Innitial Array";
        return 1;
    } else if (stringArr.empty()) {
        cout << "Array is empty!" << endl;
        return 0;
    } else {
        arr = numStringFloatConvert(stringArr);
    }
    
    cout << "\nInitial Array: " << formatArray(arr) << endl;
    
    vector<float> sortedArr = arr;
    SortStats stats;
    
    cout << "\nSorting:" << endl;
    
    quickSort(sortedArr, 0, sortedArr.size() - 1, stats);
    
    for (size_t i = 0; i < stats.steps.size(); ++i) {
        cout << stats.steps[i] << endl;
    }

    cout << "Sorted Array: " << formatArray(sortedArr) << endl;
    cout << "Comparisons: " << stats.comparisons << endl;
    
    bool comparisonResult = compareWithStdSort(arr);
    
    if (comparisonResult) {
        cout << "\nValid" << endl;
    } else {
        cout << "\nInvalid" << endl;
    }
    
    return 0;
}