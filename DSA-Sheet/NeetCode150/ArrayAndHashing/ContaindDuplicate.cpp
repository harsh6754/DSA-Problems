#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool hasDuplicate(vector<int>& nums){
        int size = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<size;i++){
            mp[nums[i]]++;
        }
        for(auto& i : mp){
            if(i.second == 2) return 1;
        } 
        return 0;
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
    bool result = solution.hasDuplicate(nums);
    cout<<result ? 1 : 0;
    return 0;
}
