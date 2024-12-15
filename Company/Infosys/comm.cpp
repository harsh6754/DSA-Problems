#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countDistinctCommonSubsequences(const string& s, const string& t) {
    int n = s.size();
    int m = t.size();

    // Create a 2D array to store the number of distinct common subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases:
    // - If either string is empty, there is only 1 empty common subsequence
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = 1;
    }

    // Calculate the number of distinct common subsequences
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // If characters at current positions match
            if (s[i - 1] == t[j - 1]) {
                // Count subsequences with and without the current character
                dp[i][j] = (dp[i - 1][j - 1] * 2 + 1) % MOD;
            } else {
                // Count subsequences without the current character
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
            }
            // Handle negative modulo values correctly
            if (dp[i][j] < 0) {
                dp[i][j] = (dp[i][j] + MOD) % MOD; 
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int result = countDistinctCommonSubsequences(s, t);
    cout << result << endl;

    return 0;
}