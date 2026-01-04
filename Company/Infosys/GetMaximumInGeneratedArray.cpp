#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int getMaximumGenerated(int n){
        if(n == 0) return 0;
        vector<int>nums(n+1);
        nums[0] = 0;
        nums[1] = 1;
        int ans = 1;
        for(int i = 1;2*i<=n;i++){
            nums[2*i] = nums[i];
            ans = max(ans,nums[2*i]);
            if(2*i+1<=n){
                nums[2*i+1] = nums[i] + nums[i+1];
                ans = max(ans,nums[2*i+1]);
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.getMaximumGenerated(n);
    cout<<result<<endl; 

    return 0;
}