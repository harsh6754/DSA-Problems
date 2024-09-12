#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>getFinalState(vector<int>nums,int k, int multiplier){
        for(int i = 0;i<k;i++){
            int ans = INT_MAX;
            int index = -1;
            for(int j = 0;j<nums.size();j++){
                if(ans>nums[j]){
                    ans = nums[j];
                    index = j;
                }
            }
            nums[index] = nums[index] * multiplier;
        }
        return nums;
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

    int multiplier;
    cin>>multiplier;

    Solution solution;
    vector<int>result = solution.getFinalState(nums,k,multiplier);
    for(auto& x : result){
        cout<<x<<" ";
    }

    return 0;
}