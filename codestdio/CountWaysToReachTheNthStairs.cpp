#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int solve(int i, int n, vector<int>& dp){
    if(i == n) return 1;
    else if(i > n) return 0;
    else if(dp[i] != -1) return dp[i];
    else{
        int total = 0;
        total += solve(i + 1, n, dp);
        total %= M;
        total += solve(i + 2, n, dp);
        total %= M;
        return dp[i] = total;
    }
}

int countDistinctWays(int n) {
    vector<int> dp(n + 1, -1);
    return solve(0, n, dp);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = countDistinctWays(n);

    cout << "The number of distinct ways to climb the stairs is: " << result << endl;

    return 0;
}
