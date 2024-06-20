#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringUtil(s, 0, s.length(), k);
    }
    
    int longestSubstringUtil(string& s, int start, int end, int k) {
        if (end - start < k) return 0; // Base case: if the segment is shorter than k, it can't have k repeating chars.
        
        unordered_map<char, int> countMap;
        for (int i = start; i < end; ++i) {
            countMap[s[i]]++;
        }
        
        for (int i = start; i < end; ++i) {
            if (countMap[s[i]] < k) {
                int j = i + 1;
                while (j < end && countMap[s[j]] < k) j++;
                return max(longestSubstringUtil(s, start, i, k), longestSubstringUtil(s, j, end, k));
            }
        }
        
        return end - start;
    }
};

int main() {
    string s;
    getline(cin, s);

    int k;
    cin >> k;

    Solution solution;
    int result = solution.longestSubstring(s, k);
    cout << result;

    return 0;
}
