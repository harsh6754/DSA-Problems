#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int Rows_size = grid.size();
        int Cols_size = grid[0].size();
        
    }
};
int main(){
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<int>>grid(rows,vector<int>(cols));
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cin>>grid[i][j];
        }
    }

    Solution solution;
    int result = solution.uniquePathsWithobstacles(grid);
    cout<<result;

    return 0;
}