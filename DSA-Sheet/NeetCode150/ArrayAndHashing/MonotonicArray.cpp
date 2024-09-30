#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    bool isMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            increasing = false;
        } else if (nums[i] > nums[i - 1]) {
            decreasing = false;
        }

        if (!increasing && !decreasing) {
            return false;
        }
    }

    return true;
}
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    Solution solution;
    bool result = solution.isMonotonic(nums);
    cout<<result ? 1 : 0;

    return 0;
}