#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minCoins(vector<int>&coins, int N, int V){
        vector<int>dp(V+1,INT_MAX);
        dp[0]=0;
        for(int i = 0;i<N;i++){
            for(int j = coins[i];j<=V;j++){
                if(dp[j-coins[i]]!=INT_MAX){
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        if(dp[V]==INT_MAX){
            return -1;
        }   
        return dp[V];
    }
};
int main(){
    int N;
    cin>>N;

    vector<int> coins(N);
    for(int i = 0;i<N;i++){
        cin>>coins[i];
    }

    int V;
    cin>>V;

    Solution solution;
    int result = solution.minCoins(coins,N,V);
    cout<<result<<endl;

    return 0;
}