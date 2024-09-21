#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};  // Correct way to return a vector
                }
            }
        }
        return {}; // Return an empty vector if no solution is found
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
    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        for (auto& i : result) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
