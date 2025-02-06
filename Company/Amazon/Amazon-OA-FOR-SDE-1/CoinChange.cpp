#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    if (dp[i - coins[j]] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    Solution sol;
    int result = sol.coinChange(coins, amount);
    if (result == -1) {
        cout << "It's not possible to make the amount with the given coins." << endl;
    } else {
        cout << "The minimum number of coins needed: " << result << endl;
    }

    return 0;
}