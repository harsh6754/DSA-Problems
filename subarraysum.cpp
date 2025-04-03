#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long subarraysum(vector<int>& arr){
        int n = arr.size();
        long result = 0;
        for(int i = 0;i<n;i++){
            result+=(long long)(arr[i]*(i+1)*(n-i));
        }
        return result;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    long result = solution.subarraysum(arr);
    cout<<result;

    return 0;
}