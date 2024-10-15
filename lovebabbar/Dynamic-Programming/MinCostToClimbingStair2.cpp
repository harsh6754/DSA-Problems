#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    int solve(vector<int>& costs, int n,vector<int>& dp){
        if(n == 0) return costs[0];
        if(n == 1) return costs[1];

        if(dp[n]!= -1){
            return dp[n];
        }

        dp[n] = costs[n] + min(solve(costs,n-1,dp) + solve(costs,n-2,dp));
        return dp[n];
    }

    int minCostToClimbingStair(vector<int>& costs){
        int n = costs.size();
        vector<int>dp(n+1,-1);
        int ans = min(solve(costs,n-1,dp),solve(costs,n-2,dp));
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>costs(n);
    for(int i = 0;i<n;i++){
        cin>>costs[i];
    }

    Solution solution;
    int result = solution.minCostToClimbingStair(costs);
    cout<<result;

    return 0;
}