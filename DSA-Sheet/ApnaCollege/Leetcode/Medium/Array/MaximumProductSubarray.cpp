#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxProduct(vector<int>& nums){
        int size = nums.size();
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        for(int i = 1;i<size;i++){
            if(nums[i]<0){
                swap(maxProduct,minProduct);
            }
            maxProduct = max(nums[i],maxProduct*nums[i]);
            minProduct = min(nums[i],minProduct*nums[i]);
            result = max(result,maxProduct);
        }
        return result;
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
    int result = solution.maxProduct(nums);
    cout<<result;

    return 0;
}