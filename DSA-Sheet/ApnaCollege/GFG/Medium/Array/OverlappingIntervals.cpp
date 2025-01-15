#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr){
        vector<vector<int>> result;
        if(arr.size() == 0){
            return result;
        }
        sort(arr.begin(),arr.end());
        vector<int> temp = arr[0];
        for(auto it:arr){
            if(it[0]<=temp[1]){
                temp[1] = max(it[1],temp[1]);
            }else{
                result.push_back(temp);
                temp = it;
            }
        }
        result.push_back(temp);
        return result;
    }
};
int main(){
    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(2));
    for(int i = 0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    Solution solution;
    vector<vector<int>>result = solution.mergeOverlap(arr);
    for(auto x:result){
        cout<<x[0]<<" "<<x[1]<<endl;
    };

    return 0;
}