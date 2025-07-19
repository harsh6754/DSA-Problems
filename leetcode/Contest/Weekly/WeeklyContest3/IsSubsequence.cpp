#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m > n) return false;

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < m && s[j] == t[i]) {
                j++;
            }
        }

        return j == m;
    }
};

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution solution;
    bool result = solution.isSubsequence(s, t);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
