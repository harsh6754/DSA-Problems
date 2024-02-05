#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char, int> mp;
        for (auto a : s) mp[a]++;


        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1) {
               
                return i;
            }
        }
        return -1;
    }
}; 

int main()
{
    string s;
    cin>>s;

    Solution solution;
    int result = solution.firstUniqChar(s);
    cout<<result;

    return 0;
}