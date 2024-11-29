#include <iostream>
#include <map>

using namespace std;

char mostFrequentVowel(const string& str) {
    map<char, int> vowelCounts;
    string vowels = "aeiouAEIOU";

    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            vowelCounts[c]++;
        }
    }

    char mostFrequent = ' ';
    int maxCount = 0;

    for (auto& entry : vowelCounts) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostFrequent = entry.first;
        }
    }

    return mostFrequent;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    char result = mostFrequentVowel(str);

    if (result != ' ') {
        cout << "The most frequent vowel is: " << result << endl;
    } else {
        cout << "No vowels found in the string." << endl;
    }

    return 0;
}