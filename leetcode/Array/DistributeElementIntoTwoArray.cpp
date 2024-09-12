#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeElements(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        
        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    Solution solution;
    vector<int> result = solution.distributeElements(nums);
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
