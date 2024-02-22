#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), k = 1, zi = -1;
        if (n == 1)
            return true;
        bool ans = false;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                zi = i;
                break;
            }
        }
        if (zi == -1)
            return true;
        else {
            k = 1;
            for (int i = zi - 1; i >= 0; i--, k++) {
                if (k < nums[i])
                    ans = true;
                if (ans == true && nums[i] == 0) {
                    zi = i;
                    ans = false;
                    k = 0;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    bool result = sol.canJump(nums);

    if (result)
        cout<<"true";
    else{
        cout<<"false";
    }

    return 0;
}
