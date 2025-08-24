#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cin>>target;

    Solution solution;
    int result = solution.search(nums,target);
    cout<<result;

    return 0;
}