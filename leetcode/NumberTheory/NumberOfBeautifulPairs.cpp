#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countBeautifulPairs(vector<int>&nums){
        
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
    int result = solution.countBeautifulPairs(nums);
    cout<<result;

    return 0;
}