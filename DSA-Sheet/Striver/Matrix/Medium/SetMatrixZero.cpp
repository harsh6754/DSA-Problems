#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void setZeroes(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool>row(n,false);   
        vector<bool>col(m,false);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    Solution solution;
    solution.setZeroes(matrix);

    return 0;
}