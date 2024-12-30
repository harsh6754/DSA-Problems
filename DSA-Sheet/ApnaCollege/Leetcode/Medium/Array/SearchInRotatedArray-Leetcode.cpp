#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (*it == target) {
                return it - nums.begin();
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cin>>target;

    Solution solution;
    int result = solution.search(nums,target);
    cout<<result;

    return 0;
}