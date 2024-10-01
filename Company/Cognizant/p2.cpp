#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeAndReplaceVowel(string s) {
        string vowels = "aeiou";
        string result;

        for (char c : s) {
            // Check if the character is a vowel
            if (vowels.find(tolower(c)) != string::npos) {
                // If it's a vowel, find the next consonant
                char nextConsonant = c; // Default to the original character
                if (tolower(c) == 'a') nextConsonant = 'b';
                else if (tolower(c) == 'e') nextConsonant = 'f';
                else if (tolower(c) == 'i') nextConsonant = 'j';
                else if (tolower(c) == 'o') nextConsonant = 'p';
                else if (tolower(c) == 'u') nextConsonant = 'v';
                result += nextConsonant; // Add the next consonant to result
            } else if (isalpha(c)) {
                // If it's a consonant, add it to the result
                result += c;
            }
        }
        return result;
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution solution;
    string result = solution.removeAndReplaceVowel(s);
    cout << result;

    return 0;
}
