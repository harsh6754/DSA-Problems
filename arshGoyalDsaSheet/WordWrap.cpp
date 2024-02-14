#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveWordWrap(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> extras(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> lc(n + 1, vector<int>(n + 1, 0));
        vector<int> c(n + 1, 0);

        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            extras[i][i] = k - nums[i - 1];
            for (int j = i + 1; j <= n; j++)
                extras[i][j] = extras[i][j - 1] - nums[j - 1] - 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (extras[i][j] < 0)
                    lc[i][j] = INT_MAX;
                else if (j == n && extras[i][j] >= 0)
                    lc[i][j] = 0;
                else
                    lc[i][j] = extras[i][j] * extras[i][j];
            }
        }
        c[0] = 0;
        for (int j = 1; j <= n; j++) {
            c[j] = INT_MAX;
            for (int i = 1; i <= j; i++) {
                if (c[i - 1] != INT_MAX && lc[i][j] != INT_MAX &&
                    (c[i - 1] + lc[i][j] < c[j])) {
                    c[j] = c[i - 1] + lc[i][j];
                    p[j] = i;
                }
            }
        }

        return c[n];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution solution;
    int result = solution.solveWordWrap(nums, k);
    cout << result;

    return 0;
}
