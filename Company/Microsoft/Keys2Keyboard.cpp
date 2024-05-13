#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int len, int copy_len, int n, vector<vector<int>> &dp, int cnt){
        if(len == n) return cnt;
        if(len > n || len + copy_len > n) return INT_MAX;
        if(dp[len][copy_len] != -1) return dp[len][copy_len];

        int copy = INT_MAX;
        int paste = INT_MAX;
        
        if(len > copy_len) copy = dfs(len, len, n, dp, cnt+1);
        if(copy_len != 0) paste = dfs(len+copy_len, copy_len, n, dp, cnt+1);

        return dp[len][copy_len] = min(copy,paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return dfs(1, 0, n, dp, 0);
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.minSteps(n);
    cout<<result;

    return 0;
}