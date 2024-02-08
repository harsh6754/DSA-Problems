#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
#include <algorithm> // for min

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Minimum number of perfect square numbers that sum up to " << n << " is: " << solution.numSquares(n) << endl;
    return 0;
}
