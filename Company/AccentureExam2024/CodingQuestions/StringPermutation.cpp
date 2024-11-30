#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to calculate permutations
int calculatePermutations(const string &remaining) {
    return factorial(remaining.length());
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string vowels = "aeiouAEIOU";
    vector<int> vowelPositions;
    string fixedVowels;
    string remainingChars;

    // Find vowels and their positions
    for (int i = 0; i < input.length(); ++i) {
        if (vowels.find(input[i]) != string::npos) {
            vowelPositions.push_back(i);
            fixedVowels += input[i];
        } else {
            remainingChars += input[i];
        }
    }

    // Check if vowels are present
    if (vowelPositions.empty()) {
        cout << "No vowels found in the string." << endl;
        return 0;
    }

    // Output fixed vowels and their positions
    cout << "Vowels found at positions: ";
    for (int pos : vowelPositions) {
        cout << pos << " ";
    }
    cout << endl;

    cout << "Vowels: " << fixedVowels << endl;

    // Calculate permutations of the remaining characters
    int permutations = calculatePermutations(remainingChars);
    cout << "Number of permutations of remaining characters: " << permutations << endl;

    return 0;
}
