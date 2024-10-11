#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for calculating Fibonacci numbers with memoization
    int fib(int n, vector<int>& dp) {
        if (n <= 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }

    // Function to return the Fibonacci sequence up to 'n'
    vector<int> fibonacci(int n) {
        vector<int> dp(n + 1, -1);  // Initialize the dp array with -1
        for (int i = 0; i <= n; i++) {
            fib(i, dp);  // Compute all Fibonacci numbers up to 'n'
        }
        return dp;
    }
};

int main() {
    int n;
    cin >> n;

    Solution solution;
    vector<int> result = solution.fibonacci(n);

    // Output the Fibonacci sequence from 0 to 'n'
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

//TC- O(N);
//SP -O(N);
