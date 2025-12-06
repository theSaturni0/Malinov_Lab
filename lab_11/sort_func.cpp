#include "sort_func.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace saturnLib;
using namespace std;

namespace saturnLib {

    string formatArray(const vector<float>& arr, int start, int end) {
        if (arr.empty()) return "[]";
        
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "[";
        
        int actualStart = (start == -1) ? 0 : start;
        int actualEnd = (end == -1) ? arr.size() - 1 : end;
        
        for (int i = actualStart; i <= actualEnd; ++i) {
            oss << arr[i];
            if (i < actualEnd) oss << ", ";
        }
        
        oss << "]";
        return oss.str();
    }

    int partition(vector<float>& arr, int low, int high, SortStats& stats, int depth) {
        float pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; ++j) {
            stats.comparisons++;
            if (arr[j] < pivot) {
                i++;
                if (i != j) {
                    swap(arr[i], arr[j]);
                    stats.swaps++;
                }
            }
        }
        
        if (i + 1 != high) {
            swap(arr[i + 1], arr[high]);
            stats.swaps++;
        }
        
        return i + 1;
    }

    void quickSort(vector<float>& arr, int low, int high, SortStats& stats, int depth) {
        static int step_counter = 1;
        
        stats.comparisons++;
        if (low < high) {
            int pi = partition(arr, low, high, stats, depth);
            
            ostringstream step;
            step << fixed << setprecision(2);
            step << "Step " << step_counter++ << ": ";
            
            vector<float> left;
            vector<float> middle;
            vector<float> right;
            
            for (int i = 0; i < arr.size(); ++i) {
                if (i == pi) {
                    middle.push_back(arr[i]);
                } else if (arr[i] < arr[pi]) {
                    left.push_back(arr[i]);
                } else {
                    right.push_back(arr[i]);
                }
            }
            
            if (!left.empty()) {
                step << formatArray(left) << " | ";
            }
            
            step << formatArray(middle);
            
            if (!right.empty()) {
                step << " | " << formatArray(right);
            }
            
            stats.steps.push_back(step.str());
            
            quickSort(arr, low, pi - 1, stats, depth + 1);
            quickSort(arr, pi + 1, high, stats, depth + 1);
        }
    }

    bool compareFloatArrays(const vector<float>& arr1, const vector<float>& arr2) {
        if (arr1.size() != arr2.size()) {
            return false;
        }
        
        const float epsilon = 1e-6f;
        for (size_t i = 0; i < arr1.size(); ++i) {
            if (abs(arr1[i] - arr2[i]) > epsilon) {
                return false;
            }
        }
        
        return true;
    }

    bool compareWithStdSort(const vector<float>& arr) {
        if (arr.empty()) {
            return true;
        }
        
        vector<float> stdSortArr = arr;
        vector<float> quickSortArr = arr;
        SortStats stats;
        
        quickSort(quickSortArr, 0, quickSortArr.size() - 1, stats);
        
        sort(stdSortArr.begin(), stdSortArr.end());
        
        bool areEqual = compareFloatArrays(quickSortArr, stdSortArr);
        
        return areEqual;
    }

}