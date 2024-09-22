#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string primary, string pattern) {
        vector<int> targetCount(26, 0);
        for (char c : pattern) {
            targetCount[c - 'a']++;
        }

        vector<int> windowCount(26, 0);
        int start = 0;
        int neededChars = pattern.size();
        long long result = 0;

        for (int end = 0; end < primary.size(); end++) {
            char currentChar = primary[end];

            if (targetCount[currentChar - 'a'] > 0) {
                if (windowCount[currentChar - 'a'] < targetCount[currentChar - 'a']) {
                    neededChars--;
                }
            }

            windowCount[currentChar - 'a']++;

            while (neededChars == 0) {
                result += primary.size() - end;

                char startChar = primary[start];
                windowCount[startChar - 'a']--;

                if (targetCount[startChar - 'a'] > 0 && 
                    windowCount[startChar - 'a'] < targetCount[startChar - 'a']) {
                    neededChars++;
                }

                start++;
            }
        }

        return result;
    }
};

int main() {
    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);

    Solution solution;
    long long result = solution.validSubstringCount(word1, word2);
    cout << result << endl;

    return 0;
}
