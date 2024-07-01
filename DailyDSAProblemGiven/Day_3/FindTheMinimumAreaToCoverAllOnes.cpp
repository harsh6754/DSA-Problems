#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = grid.size();
        int maxRow = -1;
        int minCol = grid[0].size();
        int maxCol = -1;

        for(int r=0;r<grid.size();++r)
        {
            for(int c=0;c<grid[0].size();++c)
            {
                if(grid[r][c] == 1)
                {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }
        
        if(minRow > maxRow || minCol > maxCol)
        {
            return 0;
        }

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

        return height * width;
    }
};
int main(){
    int row,col;
    cin>>row>>col;

    vector<vector<int>>grid(row,vector<int>(col));
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>grid[i][j];
        }
    }

    Solution solution;
    int result = solution.minimumArea(grid);
    cout<<result;
    return 0;
}