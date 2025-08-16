#include<bits/stdc++.h>
using namespace std;

//O(N^2) Appraoch
class Solution{
    public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n<=1) return s;

        int start = 0;
        int maxLen = 1;

        auto expand = [&](int l, int r){
            while(l>=0 && r<n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    maxLen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        };

        for(int i = 0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxLen);
    }
};

//(O(N)) Approach -->Manacher’s Algorithm

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.empty()) return "";

//         // Step 1: Transform string
//         string t = "#";
//         for(char c : s) {
//             t += c;
//             t += "#";
//         }

//         int n = t.size();
//         vector<int> p(n, 0); // radius array
//         int center = 0, right = 0;
//         int maxLen = 0, start = 0;

//         // Step 2: Expand palindromes
//         for(int i = 0; i < n; i++) {
//             int mirror = 2*center - i;
//             if(i < right)
//                 p[i] = min(right - i, p[mirror]);

//             // Try to expand around i
//             int l = i - (p[i] + 1);
//             int r = i + (p[i] + 1);
//             while(l >= 0 && r < n && t[l] == t[r]) {
//                 p[i]++;
//                 l--;
//                 r++;
//             }

//             // Update center and right boundary
//             if(i + p[i] > right) {
//                 center = i;
//                 right = i + p[i];
//             }

//             // Track longest palindrome
//             if(p[i] > maxLen) {
//                 maxLen = p[i];
//                 start = (i - maxLen) / 2; // convert index in transformed string
//             }
//         }

//         return s.substr(start, maxLen);
//     }
// };

int main(){
    string s;
    getline(cin,s);

    Solution solution;
    string result = solution.longestPalindrome(s);
    cout<<result;

    return 0;
}