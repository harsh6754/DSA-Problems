#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void printAllCombinationSetUtil(vector<int>& arr, int r, vector<int>&data, vector<vector<int>>&result, int index, int i){
        if(index == r){
            result.push_back(data);
            return;
        }

        if(i >= arr.size()){
            return;
        }

        data[index] = arr[i];
        printAllCombinationSetUtil(arr,r,data,result,index+1,i+1);
        printAllCombinationSetUtil(arr,r,data,result,index,i+1);
    }

    vector<vector<int>> printAllCombinationSet(vector<int>& arr, int r){
        vector<vector<int>>result;
        vector<int>data(r);
        printAllCombinationSetUtil(arr,r,data,result,0,0);
        return result;
    }
};


int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int r;
    cin>>r;

    Solution solution;
    vector<vector<int>>result = solution.printAllCombinationSet(arr,r);
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}