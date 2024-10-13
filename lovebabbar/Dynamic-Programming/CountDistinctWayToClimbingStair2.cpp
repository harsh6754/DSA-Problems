#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class Solution {
    public:
    int solve(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if(n >= 1) dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n]%MOD;
    }

    int CountDistinctWayToClimbingStair(int n) {
        return solve(n);
    }
};

int main() {
    int n;
    cin >> n;

    Solution solution;
    int result = solution.CountDistinctWayToClimbingStair(n);
    cout << result;

    return 0;
}
