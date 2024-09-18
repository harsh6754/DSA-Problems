#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        int a = -1;
        
        // Traverse the sorted array
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 && nums[i] != nums[i + 1]) {
                a = nums[i];
            } else if (i > 0 && i < nums.size() - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                if (a == -1) {
                    a = nums[i];
                } else {
                    return {a, nums[i]};
                }
            } else if (i == nums.size() - 1 && nums[i] != nums[i - 1]) {
                return {a, nums[i]};
            }
        }
        return {};
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    // Input the array elements
    for (auto& x : nums) {
        cin >> x;
    }

    Solution solution;
    vector<int> result = solution.singleNumber(nums);
    
    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
