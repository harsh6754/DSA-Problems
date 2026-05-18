#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i = 0;i<4;i++){
            bool flag = true;
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(mat[j][k] != target[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) return true;

            vector<vector<int>> temp(n,vector<int>(n));
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    temp[k][n-1-j] = mat[j][k];
                }
            }
            mat = temp;
        }
        return false;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> target(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>target[i][j];
        }
    }

    Solution sol;
    bool ans = sol.findRotation(mat,target);
    cout << (ans ? "true" : "false");

    return 0;
}
