#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char c : s) result ^= c;
        for (char c : t) result ^= c;
        return result;
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    Solution solution;
    char result = solution.findTheDifference(s, t);
    cout << result << endl;

    return 0;
}
