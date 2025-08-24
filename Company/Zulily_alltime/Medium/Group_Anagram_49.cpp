#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}