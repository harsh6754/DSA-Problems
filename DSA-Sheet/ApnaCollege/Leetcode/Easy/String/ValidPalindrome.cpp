#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1);
    }

    bool validPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return validPalindrome(s, i + 1, j) || validPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};

int main(){
    string s;
    cin>>s;

    Solution solution;
    bool result = solution.validPalindrome(s);
    cout<<result ? 1 : 0;

    return 0;
}