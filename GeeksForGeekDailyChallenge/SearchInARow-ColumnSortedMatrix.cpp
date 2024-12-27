#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool matSearch(vector<vector<int>> &mat, int target) {
        int n = mat.size(), m = mat[0].size();
        
        int i = 0, j = m-1;
        
        while(i < n && j >= 0){
            if(mat[i][j] == target) return true;
            
            if(mat[i][j] < target){
                i += 1;
            }else{
                j -= 1;
            }
        }
        
        return false;
    }
};
int main(){
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>> mat(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    int target;
    cin>>target;

    Solution solution;

    bool result = solution.matSearch(mat,target);
    cout<<result ? 1 : 0;

    return 0;

}