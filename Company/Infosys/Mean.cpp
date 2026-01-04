#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    double mean(vector<int>&arr, int n){
        double sum = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
        } 
        return sum/n;
    }
};
int main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    double result = solution.mean(arr,n);
    cout<<result<<endl;

    return 0;
}