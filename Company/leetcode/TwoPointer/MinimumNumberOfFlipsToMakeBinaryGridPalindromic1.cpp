#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        
        int k=0;
        for(int i=0;i<m;i++){
            int c=0;
            int l=0,r=grid[i].size()-1;

            while(l<r){
                if(grid[i][l]!=grid[i][r]) c++;
                l++;
                r--;
            }
            k+=c;
        }

        int c=0;
        for (int i=0;i<n;i++) {
            int l=0,r=m-1;
            while(l<r){
                if(grid[l][i]!=grid[r][i]) c++;
                l++;
                r--;
            }
        }

        return min(k,c);
    }
};
int main(){
    int row;
    int col;
    cin>>row>>col;

    vector<vector<int>>grid(row,vector<int>(col));
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>grid[i][j];
        }
    }

    Solution solution;
    int result = solution.minFlips(grid);
    cout<<result;

    return 0;
}