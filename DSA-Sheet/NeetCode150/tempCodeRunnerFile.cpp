#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = (n * (n + 1)) / 2; // Sum of numbers from 0 to n
        int actual_sum = 0;
        for (auto& x : nums) actual_sum += x; // Sum of elements in the array
        return expected_sum - actual_sum; // The missing number
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto& i : nums) cin >> i;

    Solution solution;
    int result = solution.missingNumber(nums);
    cout << result << endl;

    return 0;
}
