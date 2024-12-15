#include <bits/stdc++.h>
using namespace std;

int GetAnswer(int n, int m, string s, string t) {
    const int MOD = 1000000007;

    // DP table to store the number of distinct common subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the base case, where one string is empty
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;  // Empty string vs any substring of t (count of subsequences is 1 for empty string)
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;  // Empty string vs any substring of s (count of subsequences is 1 for empty string)
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                // If characters match, we add subsequences from previous states
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
            } else {
                // If characters do not match, we take subsequences from previous states
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
            }
            // Ensure the result is non-negative by taking modulo
            if (dp[i][j] < 0) {
                dp[i][j] += MOD;
            }
        }
    }

    // Subtract 1 to exclude the empty subsequence
    return (dp[n][m] - 1 + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inputline;
    getline(cin, inputline);
    int n = stoi(inputline);  // Length of the first string
    
    getline(cin, inputline);
    int m = stoi(inputline);  // Length of the second string

    getline(cin, inputline);
    string s = inputline;  // First string

    getline(cin, inputline);
    string t = inputline;  // Second string

    int result = GetAnswer(n, m, s, t);

    cout << result << "\n";
    return 0;
}
