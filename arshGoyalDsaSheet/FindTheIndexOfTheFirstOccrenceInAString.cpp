#include <iostream>
using namespace std;

class Solution {
public:
    int solve(string &s, string &part) {
        int ind = s.find(part);
        if (ind != string::npos) return ind;
        return -1;
    }

    int strStr(string haystack, string needle) {
        return solve(haystack, needle);
    }
};

int main() {
    string haystack, needle;
    
    cout << "Enter the haystack string: ";
    cin >> haystack;
    
    cout << "Enter the needle string: ";
    cin >> needle;

    Solution sol;
    int result = sol.strStr(haystack, needle);
    cout << "Index of needle in haystack: " << result << endl;

    return 0;
}
