#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007

class Solution{
    public:
    int countDistinctWayToClimbingStair(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;

        vector<int> dp(n+1);
        dp[0] = 1;  
        dp[1] = 1; 

        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }

        return dp[n];
    }
};

int main(){
    int n;
    cin >> n;

    Solution solution;
    int result = solution.countDistinctWayToClimbingStair(n);
    cout << result << endl;

    return 0;
}
