#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToClimbingStairs(vector<int>& costs) {
        int n = costs.size();
        if (n == 1) return costs[0];
        if (n == 2) return min(costs[0], costs[1]);

        vector<int> dp(n);
        dp[0] = costs[0];
        dp[1] = costs[1];

        // Fill the dp array in bottom-up manner
        for (int i = 2; i < n; i++) {
            dp[i] = costs[i] + min(dp[i-1], dp[i-2]);
        }

        // The final cost to reach the top is the minimum of the last two steps
        return min(dp[n-1], dp[n-2]);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    Solution solution;
    int result = solution.minCostToClimbingStairs(costs);
    cout << result;
    return 0;
}
