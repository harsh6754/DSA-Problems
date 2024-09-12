#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0) 
            return a;
        return GCD(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[nums.size() - 1];
        return GCD(max, min);
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
    int result = solution.findGCD(nums);
    cout << result;

    return 0;
}
