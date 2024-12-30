#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the element just larger than nums[i] to swap
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap nums[i] and nums[j]
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements from i+1 to the end
        reverse(nums.begin() + i + 1, nums.end());
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
    solution.nextPermutation(nums);

    // Print the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
