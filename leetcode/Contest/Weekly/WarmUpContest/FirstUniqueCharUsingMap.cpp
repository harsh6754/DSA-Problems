#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Find first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution solution;
    int result = solution.firstUniqChar(s);

    cout << "First unique character index: " << result << endl;
    return 0;
}
