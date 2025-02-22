#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }

        if(i>=0){
            int j = n-1;
            while(j>=0 && nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }

        reverse(nums.begin()+i+1,nums.end());
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    Solution solution ;
    solution.nextPermutation(nums);

    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}