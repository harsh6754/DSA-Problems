#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int printLeftElement(vector<int>& arr, int n){
        if(n == 0){
            return -1;
        }
        if(n == 1){
            return arr[0];
        }

        sort(arr.begin(), arr.end());
        return arr[(n-1)/2];    
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    int result = solution.printLeftElement(arr,n);
    cout<<result<<endl;

    return 0;
}