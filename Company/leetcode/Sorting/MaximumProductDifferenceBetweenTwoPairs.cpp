#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int prod1 = nums[size - 1] * nums[size - 2];
        int prod2 = nums[0] * nums[1];
        return prod1 - prod2;
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
    int result = solution.maxProductDifference(nums);
    cout<<result;
    return 0;
}