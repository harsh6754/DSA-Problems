#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to remove vowels from a string
string removeVowels(const string& str) {
    string result;
    for (char ch : str) {
        if (!((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'))) {
            result += ch;
        }
    }
    return result;
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    // Input string array
    vector<string> strArray = {"Sex", "Gand", "Mihir", "Keshav"};
    
    // Vector to store lengths of modified strings
    vector<int> lengths;
    unsigned long long maxFactorial = 0;
    
    // Process each string in the array
    for (const string& str : strArray) {
        string modifiedStr = removeVowels(str);
        int length = modifiedStr.length();
        lengths.push_back(length);
        unsigned long long fact = factorial(length);
        maxFactorial = max(maxFactorial, fact);
    }
    
    // Output the maximum factorial
    cout << "Maximum factorial: " << maxFactorial << endl;
    
    return 0;
}