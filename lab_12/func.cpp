#include "func.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

namespace saturnLib {

    map<char, int> calculateFrequency(const string& text) {
        map<char, int> frequency;
        
        for (char c : text) {
            frequency[c]++;
        }
        
        return frequency;
    }

    char getMostFrequentCharacter(const map<char, int>& frequency) {
        if (frequency.empty()) return '\0';
        
        auto maxElement = max_element(
            frequency.begin(),
            frequency.end(),
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second < b.second;
            }
        );
        
        return maxElement->first;
    }

    char getLeastFrequentCharacter(const map<char, int>& frequency) {
        if (frequency.empty()) return '\0';
        
        auto minElement = min_element(
            frequency.begin(),
            frequency.end(),
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second < b.second;
            }
        );
        
        return minElement->first;
    }

    CharacterStats getCharacterStats(const string& text) {
        CharacterStats stats = {0, 0, 0, 0, 0};
        
        for (char c : text) {
            if (isalpha(c)) {
                stats.letters++;
            } else if (isdigit(c)) {
                stats.digits++;
            } else if (isspace(c)) {
                stats.spaces++;
            } else {
                stats.others++;
            }
            stats.total++;
        }
        
        return stats;
    }

    vector<pair<char, int>> getTopFrequencies(
        const map<char, int>& frequency, 
        int n) {
        
        vector<pair<char, int>> sorted(frequency.begin(), frequency.end());
        
        sort(
            sorted.begin(), 
            sorted.end(),
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second > b.second;
            });
        
        if (n > static_cast<int>(sorted.size())) {
            n = sorted.size();
        }
        
        return vector<pair<char, int>>(sorted.begin(), sorted.begin() + n);
    }

    void printHistogram(const map<char, int>& frequency, int n) {
        if (frequency.empty()) {
            cout << "Empty\n";
            return;
        }
        
        auto topFrequencies = getTopFrequencies(frequency, n);
        
        cout << "\nHistogram (top-" << topFrequencies.size() << "):\n";
        
        int maxFreq = topFrequencies[0].second;
        const int maxBarWidth = 10;
        
        for (const auto& item : topFrequencies) {
            char ch = item.first;
            int freq = item.second;
            
            cout << "'" << ch << "': ";
            
            int barLength = (freq * maxBarWidth) / maxFreq;
            if (barLength == 0 && freq > 0) barLength = 1;
            
            for (int i = 0; i < barLength; ++i) {
                cout << "#";
            }
            
            cout << " (" << freq << ")\n";
        }
    }

    void printFrequencyTable(const map<char, int>& frequency) {
        cout << "Symbol frequency:\n";
        for (const auto& item : frequency) {
            char ch = item.first;
            int freq = item.second;
            
            if (isspace(ch)) {
                cout << "' ' (space): " << freq << "\n";
            } else {
                cout << "'" << ch << "': " << freq << "\n";
            }
        }
    }

    void printFullAnalysis(const string& text) {
        if (isTextEmpty(text)) {
            cout << "Empty.\n";
            return;
        }
        
        map<char, int> frequency = calculateFrequency(text);
        
        printFrequencyTable(frequency);
        
        char mostFreq = getMostFrequentCharacter(frequency);
        char leastFreq = getLeastFrequentCharacter(frequency);
        
        cout << "\nMost common symbol: '" << mostFreq 
            << "' (included " << frequency.at(mostFreq) << " times)\n";
        cout << "Most rare symbol: '" << leastFreq 
            << "' (included " << frequency.at(leastFreq) << " times)\n";
        
        CharacterStats stats = getCharacterStats(text);
        cout << "\nNumber of:\n";
        cout << "Letters: " << stats.letters << "\n";
        cout << "Numbers: " << stats.digits << "\n";
        cout << "Spaces: " << stats.spaces << "\n";
        cout << "Other symbols: " << stats.others << "\n";
        cout << "Total symbols: " << stats.total << "\n";
        
        printHistogram(frequency, 5);
    }

    bool isTextEmpty(const string& text) {
        return text.empty();
    }

}