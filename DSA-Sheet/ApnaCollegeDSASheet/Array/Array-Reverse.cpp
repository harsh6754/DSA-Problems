#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void reverseArray(vector<int>& arr){
        int n = arr.size();
        for(int i = 0;i<n/2;i++){
            swap(arr[i],arr[n-i-1]);
        }
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
    solution.reverseArray(arr);
    return 0;
}