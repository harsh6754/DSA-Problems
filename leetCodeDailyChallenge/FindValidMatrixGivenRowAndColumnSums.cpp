#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();
        vector<vector<int>> ans(row, vector<int>(col, 0));

        int i = 0, j = 0;
        while (i < row && j < col) {
            int val = min(rowSum[i], colSum[j]);
            ans[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            
            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        return ans;
    }
};

int main() {
    int rowSums, colSums;
    cin >> rowSums >> colSums;

    vector<int> rowSum(rowSums), colSum(colSums);
    for (int i = 0; i < rowSums; i++) {
        cin >> rowSum[i];
    }
    for (int i = 0; i < colSums; i++) {
        cin >> colSum[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.restoreMatrix(rowSum, colSum);
    for (int i = 0; i < rowSums; i++) {
        for (int j = 0; j < colSums; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
