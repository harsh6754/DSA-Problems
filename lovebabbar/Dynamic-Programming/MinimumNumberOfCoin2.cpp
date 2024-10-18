#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coin, int x, vector<int>& dp) {
        // Base case
        if (x == 0) return 0;
        if (x < 0) return INT_MAX; // Invalid case

        // If already computed, return stored value
        if (dp[x] != -1) return dp[x];

        int mini = INT_MAX;
        for (int i = 0; i < coin.size(); i++) {
            int res = solve(coin, x - coin[i], dp);
            if (res != INT_MAX) {
                mini = min(mini, res + 1); // Add 1 because we used one coin
            }
        }

        // Store result in dp array
        dp[x] = mini;
        return mini;
    }

    int minCoin(vector<int>& coin, int x) {
        // DP array to store results, initialized to -1
        vector<int> dp(x + 1, -1);
        int ans = solve(coin, x, dp);

        // If ans is still INT_MAX, that means it's impossible to form amount x
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int x;
    cin >> x;

    Solution solution;
    int result = solution.minCoin(coin, x);
    cout << result;

    return 0;
}
