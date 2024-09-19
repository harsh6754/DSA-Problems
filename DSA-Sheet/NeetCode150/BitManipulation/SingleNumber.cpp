#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int singleNumber(vector<int>&nums){
        int size = nums.size();
        unordered_map<int,int>mp;
        for(auto& x: nums) mp[x]++;
        for(auto& i:mp){
            if(i.second == 1) return i.first;
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
    Solution solution;
    int result = solution.singleNumber(nums);
    cout<<result;
    return 0;
}