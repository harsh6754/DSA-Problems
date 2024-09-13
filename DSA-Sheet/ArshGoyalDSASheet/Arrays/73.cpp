#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void setZeroes(vector<vector<int>>& matrix){
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        vector<bool> rowFlag(row_size, false);
        vector<bool> colFlag(col_size, false);
    
        for(int i = 0; i < row_size; i++) {
            for(int j = 0; j < col_size; j++) {
               if(matrix[i][j] == 0) {
                rowFlag[i] = true;
                colFlag[j] = true;
            }
        }
    }
    for(int i = 0; i < row_size; i++) {
        if(rowFlag[i]) {
            for(int j = 0; j < col_size; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 0; j < col_size; j++) {
        if(colFlag[j]) {
            for(int i = 0; i < row_size; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    }
};
int main(){
    int row,col;
    cin>>row>>col;

    vector<vector<int>>matrix(row,vector<int>(col));
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>matrix[i][j];
        }
    }


    Solution solution;
    solution.setZeroes(matrix);
     for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}