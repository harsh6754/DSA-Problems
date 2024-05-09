#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    bool containsDuplicate(vector<int>&nums){
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size() - 1;i++)
        {
            if(nums[i] == nums[i+1]){
                return 1;
            }
        }
        return 0;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }

    Solution solution;
    bool result = solution.containsDuplicate(nums);
    cout<<result;
    if(!result){
        return 0;
    }else{
        return 1;
    }


    return 0;
}