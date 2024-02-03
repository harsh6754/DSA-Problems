#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            int currMax = 0;
            for (int j = 1; j <= min(k, i); j++) {
                currMax = max(currMax, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + currMax * j);
            }
        }
        return dp[N];
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.maxSumAfterPartitioning(arr, k);
    cout << "Maximum sum after partitioning: " << result << endl;

    return 0;
}
