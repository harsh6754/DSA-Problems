#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findMinOps(vector<int>& arr){
        int size = arr.size();
        int count = 0;
        int i =0;
        int j = size-1;
        while(i<=j){
            if(arr[i] == arr[j]){
                i++;
                j--;
            }
            else if(arr[i]>arr[j]){
                j--;
                arr[j] += arr[j+1];
                count++;
            }
            else{
                i++;
                arr[i] += arr[i-1];
                count++;
            }
        }
        return count;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    int result = solution.findMinOps(arr);
    cout<<result;

    return 0;
}