#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans; 

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (mp.find(temp) != mp.end()) {
                ans[mp[temp]].push_back(strs[i]);
            } else {
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "Anagrams grouped:" << endl;
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    cout << "Number of groups of anagrams: " << result.size() << endl;

    return 0;
}
