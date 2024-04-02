#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                count++;
                if (count > 1)
                    return false;
                if (i > 1 && nums[i] <= nums[i - 2])
                    nums[i] = nums[i - 1];
            }
        }
        return true;
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
    bool result = solution.canBeIncreasing(nums);
    cout << (result ? "true" : "false");

    return 0;
}
