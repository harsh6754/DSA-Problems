#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string s;
    getline(cin, s);  // Input the whole line (supports spaces)

    Solution solution;
    int result = solution.firstUniqChar(s);

    cout << "First unique character index: " << result << endl;

    return 0;  // Return success
}
