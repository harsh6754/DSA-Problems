#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string input;
    unordered_map<char, int> charCount;

    // Input the string
    cin >> input;

    // Count the occurrences of each character in the string
    for (char ch : input) {
        charCount[ch]++;
    }

    // Find the first non-repetitive character
    char nonRepetitive = ' ';
    for (char ch : input) {
        if (charCount[ch] == 1) {
            nonRepetitive = ch;
            break;
        }
    }

    // Display the result
    if (nonRepetitive != ' ') {
        cout << nonRepetitive << endl;
    } else {
        cout << "All the characters are repetitive" << endl;
    }

    return 0;
}
