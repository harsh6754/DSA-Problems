#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pairInSortedRotated(vector<int>& nums, int target) {
        unordered_map<int, int> complementMap;
        for (int num : nums) {
            // Check if the current number's complement exists in the map
            if (complementMap.find(target - num) != complementMap.end()) {
                return true;
            }
            // Add the current number to the map
            complementMap[num]++;
        }
        return false;
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
    bool result = solution.pairInSortedRotated(nums, target);
    cout << (result ? 1 : 0);

    return 0;
}
