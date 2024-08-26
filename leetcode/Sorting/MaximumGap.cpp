#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Find the maximum difference between consecutive elements
        int maxGap = 0;
        for (int i = 1; i < size; i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }

        return maxGap;
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
    int result = solution.maximumGap(nums);
    cout << result;

    return 0;
}
