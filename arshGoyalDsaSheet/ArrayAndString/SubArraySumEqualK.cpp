#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        unordered_map<int, int> prefixSumCount;
        int sum = 0;

        // Initialize the prefix sum with 0 to handle subarrays starting from index 0
        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // Check if there is a subarray with sum (sum - k)
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            // Increment the count of the current prefix sum
            prefixSumCount[sum]++;
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution solution;
    int result = solution.subarraySum(nums, k);
    cout << result << endl;

    return 0;
}
