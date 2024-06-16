#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0; // Count of patches needed
        int index = 0; // Index to iterate through nums
        long long nextSum = 1; // The next sum we want to achieve

        // Continue until nextSum exceeds n
        while (nextSum <= n) {
            // If the current number in nums can be used to achieve nextSum
            if (index < nums.size() && nums[index] <= nextSum) {
                nextSum += nums[index++]; // Add this number to nextSum and move to the next number in nums
            } else {
                // If we cannot achieve nextSum with the current nums, we patch by adding nextSum itself
                nextSum += nextSum;
                patches++; // Increment patches count
            }
        }

        return patches;
    }
};

int main() {
    int m;
    cout << "Enter the number of elements in the array: ";
    cin >> m;

    vector<int> nums(m);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    int result = solution.minPatches(nums, n);
    cout << "Minimum number of patches needed: " << result << endl;

    return 0;
}
