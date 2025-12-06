#pragma once

#include <vector>
#include <string>

namespace saturnLib {

struct SortStats {
    int comparisons = 0;
	int swaps = 0;
    std::vector<std::string> steps;
};

void quickSort(std::vector<float>& arr, int low, int high, SortStats& stats, int depth = 0);

std::string formatArray(const std::vector<float>& arr, int start = -1, int end = -1);

bool compareWithStdSort(const std::vector<float>& arr);

}