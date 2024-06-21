#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
          void sort012(int a[],int n){
            sort(a,a+n);
          }
};
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    Solution solution;
    solution.sort012(a,n);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}