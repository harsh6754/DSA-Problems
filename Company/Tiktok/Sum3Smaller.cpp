#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
  
                    count += right - left;
                    left++;
                } else {
 
                    right--;
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

    int target;
    cin >> target;

    Solution solution;
    int result = solution.threeSumSmaller(nums, target);
    cout << result;

    return 0;
}
