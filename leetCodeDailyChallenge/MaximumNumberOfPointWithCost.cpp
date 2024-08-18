#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int r, c;
//     vector<vector<long long>> dp;

//     long long f(int i, int j, vector<vector<int>>& points){
//         if (i == 0) return dp[i][j] = points[i][j];
//         if (dp[i][j] != -1) return dp[i][j];

//         long long max_prev = LLONG_MIN;
        
//         for (int k = 0; k < c; k++)
//             max_prev = max(max_prev, f(i - 1, k, points) - abs(j - k));

//         return dp[i][j] = max_prev + points[i][j];
//     }

//     long long maxPoints(vector<vector<int>>& points) {
//         r = points.size();
//         c = points[0].size();
//         dp.assign(r, vector<long long>(c, -1));

//         long long ans = LLONG_MIN;
//         for (int j = 0; j < c; j++)
//             ans = max(ans, f(r - 1, j, points));

//         return ans;
//     }
// };
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();
        vector<long long> prev_dp(c, 0);

        for (int j = 0; j < c; j++) {
            prev_dp[j] = points[0][j];
        }

        for (int i = 1; i < r; i++) {
            vector<long long> left(c, 0), right(c, 0), curr_dp(c, 0);

            left[0] = prev_dp[0];
            for (int j = 1; j < c; j++) {
                left[j] = max(left[j - 1], prev_dp[j] + j);
            }

            right[c - 1] = prev_dp[c - 1] - (c - 1);
            for (int j = c - 2; j >= 0; j--) {
                right[j] = max(right[j + 1], prev_dp[j] - j);
            }

            for (int j = 0; j < c; j++) {
                curr_dp[j] = max(left[j] - j, right[j] + j) + points[i][j];
            }

            prev_dp = curr_dp;
        }

        return *max_element(prev_dp.begin(), prev_dp.end());
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> points(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> points[i][j];
        }
    }

    Solution solution;
    long long result = solution.maxPoints(points);
    cout << result << endl;

    return 0;
}
