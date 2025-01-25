#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string LongestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return ""; // No strings in the input

        string prefix = strs[0]; // Assume the first string as the prefix

        for (int i = 1; i < n; i++) {
            // Compare the current prefix with the next string
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }
            // Update the prefix to the common part
            prefix = prefix.substr(0, j);
            if (prefix.empty()) return ""; // No common prefix exists
        }

        return prefix;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution solution;
    string result = solution.LongestCommonPrefix(strs);
    cout << result;

    return 0;
}
