#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int diagonalPrime(vector<vector<int>>&nums){
    
    }
};
int main(){
    int row,col;
    cin>>row,col;

    vector<vector<int>>nums(row,vector<int>(col));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>nums[i][j];
        }
    }

    Solution solution;
    int result = solution.diagonalPrime(nums);
    cout<<result;

    return 0;
}