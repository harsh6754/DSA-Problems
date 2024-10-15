#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(vector<int>& costs,int n){
        if(n == 0) return costs[0];
        if(n == 1) return costs[1];

        int rlt = costs[n] + (solve(costs,n-1) + solve(costs,n-2));
        return rlt;
    }

    int minCostsToClimbingStair(int n, vector<int>& costs){
        int ans = min(solve(costs,n-1),solve(costs,n-2));
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
    int result = solution.minCostsToClimbingStair(n,costs);
    cout<<result;
    return 0;
}