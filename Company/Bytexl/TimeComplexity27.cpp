#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int LeastPerson(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];  
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
    int result = solution.LeastPerson(nums);
    cout << result;

    return 0;
}
