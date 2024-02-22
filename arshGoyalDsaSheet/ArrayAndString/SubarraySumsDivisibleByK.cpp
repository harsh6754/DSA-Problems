#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderCount;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) {
                sum += k;
            }

            if (sum == 0) {
                count++;
            }

            if (remainderCount.find(sum) != remainderCount.end()) {
                count += remainderCount[sum];
            }
            remainderCount[sum]++;
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
    int result = solution.subarraysDivByK(nums, k);
    cout << result << endl;

    return 0;
}
