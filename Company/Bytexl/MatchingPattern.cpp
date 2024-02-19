#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    bool dp[m + 1][n + 1];

    // Initialize the first row and column of the DP table
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];  // Match 0 or more characters
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    if (isMatch(text, pattern)) {
        cout <<"True"<< endl;
    } else {
        cout <<"False"<< endl;
    }

    return 0;
}
