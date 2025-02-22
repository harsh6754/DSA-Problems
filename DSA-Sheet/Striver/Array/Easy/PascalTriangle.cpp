#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            vector<vector<int>>result;
            for(int i = 0;i<numRows;i++){
                vector<int>temp(i+1,1);
                for(int j = 1;j<i;j++){
                    temp[j] = result[i-1][j-1] + result[i-1][j];
                }
                result.push_back(temp);
            }
            return result;
        }
};
int main(){
    int numRows;
    cin>>numRows;

    Solution solution;
    vector<vector<int>> result = solution.generate(numRows);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}