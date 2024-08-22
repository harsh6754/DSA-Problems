#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[count] = nums[i]; 
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int val;
    cin >> val;

    Solution solution;
    int result = solution.removeElement(nums, val);
    cout << result;

    return 0;
}
