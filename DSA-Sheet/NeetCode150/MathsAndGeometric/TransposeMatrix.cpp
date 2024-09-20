#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        
        vector<vector<int>> transposed(col_size, vector<int>(row_size));
        
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        
        return transposed;
    }
};

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    
    Solution solution;
    vector<vector<int>> result = solution.transpose(matrix);
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
