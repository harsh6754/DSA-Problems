#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> rowFlag(rows, false);
        vector<bool> colFlag(cols, false);

        // First pass to find which rows and columns need to be zeroed
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    rowFlag[i] = true;
                    colFlag[j] = true;
                }
            }
        }

        // Second pass to set the appropriate cells to zero
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(rowFlag[i] || colFlag[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Output the modified matrix
        cout << "Modified Matrix:\n";
        for(const auto& row : matrix) {
            for(const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int row,col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;

    vector<vector<int>> matrix(row, vector<int>(col));
    cout<<"Enter the elements of the matrix:\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin>>matrix[i][j];
        }
    }

    Solution solution;
    solution.setZeroes(matrix);
    return 0;
}