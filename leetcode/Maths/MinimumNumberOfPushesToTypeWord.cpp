#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (char ch : word) {
            mp[ch] = mp.size() / 8 + 1;
            ans += mp[ch];
        }
        return ans;
    }
};
int main(){
    string word;
    getline(cin,word);

    Solution solution;
    int result = solution.minimumPushes(word);
    cout<<result;
    return 0;
}