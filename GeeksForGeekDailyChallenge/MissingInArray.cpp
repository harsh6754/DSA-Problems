
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(int n,vector<int>&arr) {
        int expectedSum = n * (n + 1) / 2; 
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += arr[i];
        }

        return expectedSum - actualSum;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n-1;i++){
        cin>>arr[i];
    }

    Solution solution;
    int result = solution.missingNumber(arr,n);
    cout<<result;

    return 0;
}