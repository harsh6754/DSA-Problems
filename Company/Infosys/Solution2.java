import java.io.*;
import java.util.*;

public class Solution {

    public static int GetAnswer(int n, int m, String s, String t) {
        final int MOD = 1000000007;
        
        // DP table to store the number of distinct common subsequences
        int[][] dp = new int[n + 1][m + 1];
        
        // Initialize the base case, where one string is empty
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;  // Empty string vs any substring of t
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 1;  // Empty string vs any substring of s
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
                } else {
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

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = Integer.parseInt(scan.nextLine().trim());
        int m = Integer.parseInt(scan.nextLine().trim());

        String s = scan.nextLine();
        String t = scan.nextLine();

        int result = GetAnswer(n, m, s, t);

        System.out.println(result);
    }
}
