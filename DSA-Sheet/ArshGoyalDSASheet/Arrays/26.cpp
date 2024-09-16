#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; 
        }
        vector<int> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.first);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> result = solution.removeDuplicate(nums);

    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
