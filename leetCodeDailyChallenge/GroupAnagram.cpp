
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
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    vector<vector<string>> groupedAnagrams = sol.groupAnagrams(strs);

    // Output the grouped anagrams
    for (const auto& group : groupedAnagrams) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
