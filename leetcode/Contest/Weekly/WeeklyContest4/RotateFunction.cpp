#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxRotateFunction(vector<int>& nums){
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        int sum = 0, k = 0;

        for(int i = 0;i<n;i++){
            sum+=nums[i];
            k+= i * nums[i];
        }

        int maxValue = k;
        for(int i = 1;i<n;i++){
            k = k + sum  - n * nums[n-i];
            maxValue = max(maxValue,k);  
        }
        return maxValue;
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
    int result = solution.maxRotateFunction(nums);
    cout<<result<<endl;

    return 0;
}