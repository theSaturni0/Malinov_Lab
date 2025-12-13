#pragma once

#include <map>
#include <string>
#include <vector>

namespace saturnLib {

struct CharacterStats {
    int letters;
    int digits;
    int spaces;
    int others;
    int total;
};

std::map<char, int> calculateFrequency(const std::string& text);
char getMostFrequentCharacter(const std::map<char, int>& frequency);
char getLeastFrequentCharacter(const std::map<char, int>& frequency);
CharacterStats getCharacterStats(const std::string& text);

std::vector<std::pair<char, int>> getTopFrequencies(
    const std::map<char, int>& frequency, 
    int n);
void printHistogram(const std::map<char, int>& frequency, int n = 5);

void printFullAnalysis(const std::string& text);

bool isTextEmpty(const std::string& text);
void printFrequencyTable(const std::map<char, int>& frequency);

}