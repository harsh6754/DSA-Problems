#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // To mark the rows and columns that need to be zeroed
        vector<int> zeroRows(rows, 0);
        vector<int> zeroCols(cols, 0);

        // Find the zero elements and mark their rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = 1;
                    zeroCols[j] = 1;
                }
            }
        }

        // Set the matrix elements to zero based on marked rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (zeroRows[i] || zeroCols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution solution;

    int n, m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    solution.setMatrixZeroes(arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
