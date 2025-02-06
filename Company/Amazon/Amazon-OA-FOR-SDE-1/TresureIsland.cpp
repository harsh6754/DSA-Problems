#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int treasureIsland(vector<vector<char>>& grid){
            if(grid.size()==0){
                return 0;
            }
            queue<pair<int,int>> q;
            q.push({0,0});
            grid[0][0] = 'D';
            int steps = 0;
            while(!q.empty()){
                int size = q.size();
                for(int i = 0;i<size;i++){
                    pair<int,int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    if(grid[x][y]=='X'){
                        return steps;
                    }
                    if(x>0 && grid[x-1][y]!='D'){
                        if(grid[x-1][y]=='X'){
                            return steps+1;
                        }
                        q.push({x-1,y});
                        grid[x-1][y] = 'D';
                    }
                    if(y>0 && grid[x][y-1]!='D'){
                        if(grid[x][y-1]=='X'){
                            return steps+1;
                        }
                        q.push({x,y-1});
                        grid[x][y-1] = 'D';
                    }
                    if(x<grid.size()-1 && grid[x+1][y]!='D'){
                        if(grid[x+1][y]=='X'){
                            return steps+1;
                        }
                        q.push({x+1,y});
                        grid[x+1][y] = 'D';
                    }
                    if(y<grid[0].size()-1 && grid[x][y+1]!='D'){
                        if(grid[x][y+1]=='X'){
                            return steps+1;
                        }
                        q.push({x,y+1});
                        grid[x][y+1] = 'D';
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
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout<<"Enter the value for grid["<<i<<"]["<<j<<"]: ";
            cin>>grid[i][j];
        }
    }

    Solution sol;
    cout<<sol.treasureIsland(grid)<<endl;

    return 0;
}