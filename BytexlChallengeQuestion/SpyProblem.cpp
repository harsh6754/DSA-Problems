#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }

private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main() {
    Solution solution;

    // Taking input from the user
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    // Calling the rob function
    int result = solution.rob(nums);

    // Displaying the result
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
