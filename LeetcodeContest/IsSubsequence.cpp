#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (int i = 0; i < t.length(); i++) {
            if (index < s.length() && s[index] == t[i]) {
                index++;
            }
        }
        return index == s.length();
    }
};

int main() {
    Solution solution;
    string s, t;
    
    cout << "Enter String s: ";
    cin >> s;

    cout << "Enter String t: ";
    cin >> t;

    bool result = solution.isSubsequence(s, t);
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}
