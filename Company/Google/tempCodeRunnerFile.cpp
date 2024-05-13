class Solution {
public:
    vector<int> subarraySum(vector<int>& nums, long long sum) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == sum) {
                    return {i, j};
                }
            }
        }
        return {}; // If no subarray with the given sum is found
    }
};