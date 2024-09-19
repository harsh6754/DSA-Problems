#include<bits/stdc++.h>
#include<numeric>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, gcd(str1.length(), str2.length()));
    }
};

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    Solution solution;
    string result = solution.gcdOfStrings(str1, str2);
    cout << result;

    return 0;
}
