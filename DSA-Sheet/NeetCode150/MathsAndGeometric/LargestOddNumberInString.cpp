#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    string num;
    getline(cin, num);

    Solution solution;
    string result = solution.largestOddNumber(num);
    cout << result << endl;

    return 0;
}
