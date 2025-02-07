#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minSteps(vector<vector<char>>& grid){
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='S'){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if(grid[x][y]=='X'){
                    return steps;
                }
                for(auto dir:dirs){
                    int newX = x+dir[0];
                    int newY = y+dir[1];
                    if(newX>=0 && newX<row && newY>=0 && newY<col && grid[newX][newY]!='D' && visited[newX][newY]==0){
                        q.push({newX,newY});
                        visited[newX][newY]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
int main(){
    int row;
    int col;
    cin>>row>>col;

    vector<vector<char>> grid(row,vector<char>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter the value of grid["<<i<<"]["<<j<<"]: ";
            cin>>grid[i][j];
        }
    }

    Solution solution;
    int result = solution.minSteps(grid);
    cout<<"Result :" << result;

    return 0;
}