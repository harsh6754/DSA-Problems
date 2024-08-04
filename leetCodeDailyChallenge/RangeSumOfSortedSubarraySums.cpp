#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static const int mod = 1e7 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }
        sort(subarraySums.begin(), subarraySums.end());
        int result = 0;
        for (int k = left - 1; k < right; ++k) {
            result = (result + subarraySums[k]) % mod;
        }
        
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int left, right;
    cin >> left >> right;

    Solution solution;
    int result = solution.rangeSum(nums, n, left, right);
    cout << result;
    return 0;
}
