#include <iostream>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};  
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x <= min(j, i - 1); x++) {
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                    }
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.kInversePairs(n, k);
    cout << "The number of arrays with " << k << " inverse pairs for length " << n << " is: " << result << endl;

    return 0;
}
