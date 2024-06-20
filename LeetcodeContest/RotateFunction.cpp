#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int F = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            F += i * nums[i];
            sum += nums[i];
        }
        int res = F;
        for (int i = 1; i < n; ++i) {
            F = F + sum - n * nums[n - i];
            res = max(res, F);
        }
        
        return res;
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
    int result = solution.maxRotateFunction(nums);
    cout << result << endl;

    return 0;
}
