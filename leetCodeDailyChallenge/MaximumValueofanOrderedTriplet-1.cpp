#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long maxLeft = nums[0]; // Maximum value to the left of the current index
        long long maxResult = 0;    // Maximum triplet value

        vector<long long> maxRight(n, 0); // Maximum value to the right of the current index
        maxRight[n - 1] = nums[n - 1];

        // Precompute the maximum values to the right
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], (long long)nums[i]);
        }

        // Iterate through the array to calculate the maximum triplet value
        for (int j = 1; j < n - 1; ++j) {
            if (nums[j] < maxLeft) { // Ensure nums[i] > nums[j]
                maxResult = max(maxResult, (maxLeft - nums[j]) * maxRight[j + 1]);
            }
            maxLeft = max(maxLeft, (long long)nums[j]);
        }

        return maxResult;
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
    long long result = solution.maximumTripletValue(nums);
    cout << result << endl;

    return 0;
}