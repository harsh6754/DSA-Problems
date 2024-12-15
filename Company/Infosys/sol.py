def get_answer(n, m, s, t):
    MOD = 1000000007

    # DP table to store the number of distinct common subsequences
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # Initialize the base case, where one string is empty
    for i in range(n + 1):
        dp[i][0] = 1  # Empty string vs any substring of t (count of subsequences is 1 for empty string)
    for j in range(m + 1):
        dp[0][j] = 1  # Empty string vs any substring of s (count of subsequences is 1 for empty string)

    # Fill the DP table
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i - 1] == t[j - 1]:
                # If characters match, we add subsequences from previous states
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD
            else:
                # If characters do not match, we take subsequences from previous states
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD

            # Ensure the result is non-negative by taking modulo
            if dp[i][j] < 0:
                dp[i][j] += MOD

    # Subtract 1 to exclude the empty subsequence
    return (dp[n][m] - 1 + MOD) % MOD

if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().strip().splitlines()
    
    n = int(data[0])  # Length of the first string
    m = int(data[1])  # Length of the second string
    s = data[2]       # First string
    t = data[3]       # Second string

    result = get_answer(n, m, s, t)
    print(result)