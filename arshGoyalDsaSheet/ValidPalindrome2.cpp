#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     bool palin(string s ,int i ,int j){
//         while(j>=i){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//             else{
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }
//     bool validPalindrome(string s) {
//         int i = 0;
//         int j = s.length()-1;
//         while(j>=i){
//             if(s[i]!=s[j]){
//                 return palin(s,i+1,j) || palin(s,i,j-1);

//             }
//             else{
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (j > i) {
            if (s[i] != s[j])
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            i++;
            j--;
        }
        
        return true;
    }

private:
    bool isPalindrome(const string& s, int start, int end) {
        while (end > start) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    string s;
    cin>>s;

    Solution solution;
    bool result = solution.validPalindrome(s);
    cout<<result;

    return 0;
}