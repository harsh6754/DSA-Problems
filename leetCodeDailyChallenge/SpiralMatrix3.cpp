#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows;
    int cols;
    cin>>rows>>cols;

    int rStart;
    int cStart;
    cin>>rStart>>cStart;

    Solution solution;
    vector<vector<int>>result = solution.spiralMatrixIII(rows,cols,rStart,cStart);
    
}