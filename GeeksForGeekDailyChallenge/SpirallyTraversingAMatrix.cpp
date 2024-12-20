#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> spirallyTraverse(vector<vector<int>> & mat){
        vector<int>ans;
        int top = 0;
        int bottom = mat.size()-1;
        int left = 0;
        int right = mat[0].size()-1;
        int dir = 0;
        while(top<=bottom && left<=right){
            if(dir == 0){
                for(int i = left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top;i<=bottom;i++){
                    ans.push_back(mat[i][right]);
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right;i>=left;i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            else if(dir == 3){
                for(int i = bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    Solution solution;
    vector<int>result = solution.spirallyTraverse(mat);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}