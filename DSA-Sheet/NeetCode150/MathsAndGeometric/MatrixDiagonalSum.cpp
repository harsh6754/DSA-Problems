#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for(int i = 0; i < n; ++i){
            sum += mat[i][i];
            sum += mat[i][n-1-i];
        }
        
        if(n&1) sum -= mat[n/2][n/2];
        
        return sum;
    }
};
int main(){
    int row;
    int col;
    cin>>row>>col;

    vector<vector<int>>mat(row,vector<int>(col));
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>mat[i][j];
        }
    }
    Solution solution;
    int result = solution.diagonalSum(mat);
    cout<<result;

    return 0;
}