#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        // Create an unordered set for efficient lookup of banned words
        unordered_set<string> bannedWordsSet(bannedWords.begin(), bannedWords.end());

        int bannedWordCount = 0;

        for (const string& word : message) {
            if (bannedWordsSet.count(word)) {
                bannedWordCount++;
                if (bannedWordCount >= 2) {
                    return true; // If two banned words are found, return true immediately
                }
            }
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> message(n);
    for (int i = 0; i < n; i++) {
        cin >> message[i];
    }

    vector<string> bannedWords(n);
    for (int i = 0; i < n; i++) {
        cin >> bannedWords[i];
    }

    Solution solution;
    bool result = solution.reportSpam(message, bannedWords);
    cout << result ? 1 : 0;
    return 0;
}