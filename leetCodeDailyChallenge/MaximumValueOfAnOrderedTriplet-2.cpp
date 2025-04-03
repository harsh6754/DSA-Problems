#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {  // Change return type to long long
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        long long ans = 0;  // Change to long long
        for (int i = 1; i < n - 1; i++) {
            long long left = leftMax[i - 1];  // Convert to long long
            long long right = rightMax[i + 1];  // Convert to long long
            ans = max(ans, (left - nums[i]) * right); // Multiplication now uses long long
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
    long long result = solution.maximumTripletValue(nums);  // Use long long
    cout << result << endl;
    return 0;
}
