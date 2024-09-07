#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool containsNearbyDuplicate(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int size = nums.size();
        for(int i = 0;i<size;i++){
            if(mp.count(nums[i])){
                if(abs(i - mp[nums[i]])<=k) return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    Solution solution;
    bool result = solution.containsNearbyDuplicate(nums,k);
    cout<<result ? 1 : 0;

    return 0;
}