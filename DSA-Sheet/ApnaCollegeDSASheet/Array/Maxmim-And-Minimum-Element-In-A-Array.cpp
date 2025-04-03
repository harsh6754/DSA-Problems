#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void maxMinElement(vector<int>& arr){
        int n = arr.size();
        int maxElement = INT_MIN;
        int minElement = INT_MAX;

        for(int i = 0;i<n;i++){
            maxElement = max(maxElement,arr[i]);
            minElement = min(minElement,arr[i]);    
        }
        cout<<"Max Element: "<<maxElement<<endl;
        cout<<"Min Element: "<<minElement<<endl;
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
    solution.maxMinElement(arr);
    return 0;
}