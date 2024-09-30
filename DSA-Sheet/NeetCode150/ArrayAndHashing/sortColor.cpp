#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto& i : nums) {
        cin >> i;
    }

    Solution solution;
    solution.sortColors(nums);

    for (int i : nums) {
        cout << i << " ";
    }

    return 0;
}
