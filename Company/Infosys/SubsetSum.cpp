#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isSubsetSum(vector<int>&set, int N, int sum){
        vector<vector<bool>>dp(N+1, vector<bool>(sum+1, false));
        for(int i = 0;i<=N;i++){
            dp[i][0]=true;
        }
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=sum;j++){
                if(set[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
};
int main(){
    int N;
    cout<<"Eneter number of elements: "<<endl;
    cin>>N;

    vector<int> set(N);
    for(int i = 0;i<N;i++){
        cin>>set[i];
    }

    int sum;
    cout<<"Enter the sum to be checked: "<<endl;
    cin>>sum;

    Solution solution;
    bool result = solution.isSubsetSum(set,N,sum);
    cout<<(result ? 1 : 0)<<endl;
    return 0;
}