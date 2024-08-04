#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canBeEqual(vector<int>&target,vector<int>&arr){
    vector<int>cnt1(1001);
    vector<int>cnt2(1001);
    for(int &v : target){
        ++cnt1[v];
    }
    for(int &v : arr){
        ++cnt2[v];
    }  
    return cnt1 == cnt2;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>target(n),arr(n);
    for(int i = 0;i<n;i++){
        cin>>target[i];
    }
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    Solution solution;
    bool result = solution.canBeEqual(target,arr);
    cout<<result ? 1 :  0 ;
    return 0;
}