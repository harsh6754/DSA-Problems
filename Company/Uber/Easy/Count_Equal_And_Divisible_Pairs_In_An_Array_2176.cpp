// 2176. Count Equal and Divisible Pairs in an Array
// Leetcode
//Easy
//Uber

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int length = nums.size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
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
    int result = solution.countPairs(nums, k);
    cout << result;

    return 0;
}
