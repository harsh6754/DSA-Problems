  int minOperations(string str1, string str2) {
        int str1_size = str1.length();
        int str2_size = str2.length();
        vector<vector<int>> dp(str1_size + 1, vector<int>(str2_size + 1));

        for (int i = 0; i <= str1_size; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= str2_size; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= str1_size; i++) {
            for (int j = 1; j <= str2_size; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[str1_size][str2_size];
    }