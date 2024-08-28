#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<int>>grid1(rows,vector<int>(cols));
    vector<vector<int>>grid2(rows,vector<int>(cols));
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cin>>grid1[i][j];
        }
    }
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cin>>grid2[i][j];
        }
    }

    Solution solution;
    
}