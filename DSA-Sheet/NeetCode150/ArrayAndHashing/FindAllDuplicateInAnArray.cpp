#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>findDuplicate(vector<int>nums){
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto &x : mp){
            if(x.second>=2){
                ans.push_back(x.first);
            }
        }
        return ans;
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
    vector<int>result = solution.findDuplicate(nums);
    for(auto &i : result) cout<<i<<" ";

    return 0;
}