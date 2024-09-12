#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return {};

        int candidate1 = 0, candidate2 = 1; // Initialize with different values
        int count1 = 0, count2 = 0;

        // First pass: Find potential candidates for majority elements
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> result;
        if (count1 > size / 3) result.push_back(candidate1);
        if (count2 > size / 3) result.push_back(candidate2);

        return result;
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
    vector<int> result = solution.majorityElement(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
