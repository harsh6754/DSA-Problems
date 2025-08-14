#include <bits/stdc++.h>
using namespace std;

int collectMax(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> dp_prev(n, vector<int>(n, -1e9));
    vector<vector<int>> dp_curr(n, vector<int>(n, -1e9));
    dp_prev[0][0] = mat[0][0] == -1 ? -1e9 : mat[0][0];

    for (int k = 1; k <= 2 * (n - 1); k++) {
        for (int x1 = max(0, k - (n - 1)); x1 <= min(n - 1, k); x1++) {
            for (int x2 = max(0, k - (n - 1)); x2 <= min(n - 1, k); x2++) {
                int y1 = k - x1;
                int y2 = k - x2;
                if (y1 >= n || y2 >= n || mat[x1][y1] == -1 || mat[x2][y2] == -1) {
                    dp_curr[x1][x2] = -1e9;
                    continue;
                }
                int best = -1e9;
                if (x1 > 0 && x2 > 0) best = max(best, dp_prev[x1 - 1][x2 - 1]);
                if (x1 > 0) best = max(best, dp_prev[x1 - 1][x2]);
                if (x2 > 0) best = max(best, dp_prev[x1][x2 - 1]);
                best = max(best, dp_prev[x1][x2]);
                if (best < 0) {
                    dp_curr[x1][x2] = -1e9;
                    continue;
                }
                int val = mat[x1][y1];
                if (x1 != x2 || y1 != y2) val += mat[x2][y2];
                dp_curr[x1][x2] = best + val;
            }
        }
        swap(dp_prev, dp_curr);
    }
    return max(0, dp_prev[n - 1][n - 1]);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << collectMax(mat) << endl;
    return 0;
}
