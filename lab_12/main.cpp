#include "func.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace saturnLib;

int main() {
    string inputText;
    cout << "Input the text:\n";
    
    getline(cin, inputText);
    
    if (isTextEmpty(inputText)) {
        cout << "Empty input.\n";
        return 1;
    }
    
    printFullAnalysis(inputText);
    
    return 0;
}