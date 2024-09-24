#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumDifference(vector<int>& nums,int k){
        int n = nums.size();
        if(n==1) return 0;
        int minDiff=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=n-k;i++){
            int min=nums[i+k-1]-nums[i];
            if(min<minDiff){
                minDiff=min;
            }
        }
        return minDiff;
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
    int result = solution.minimumDifference(nums,k);
    cout>>result;
    return 0;
}