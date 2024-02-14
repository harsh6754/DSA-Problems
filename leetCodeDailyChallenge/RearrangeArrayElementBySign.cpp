#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1, v2, ans;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        
        int ind1 = 0, ind2 = 0;
        while (ind1 < v1.size() && ind2 < v2.size()) {
            ans.push_back(v1[ind1]);
            ans.push_back(v2[ind2]);
            ind1++;
            ind2++;
        }
        
        while (ind1 < v1.size()) {
            ans.push_back(v1[ind1]);
            ind1++;
        }
        
        while (ind2 < v2.size()) {
            ans.push_back(v2[ind2]);
            ind2++;
        }
        
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
    vector<int> result = solution.rearrangeArray(nums);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
