#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minChange(int k, int n){
      int res = 0;
      for(int i = 0;i<32;i++){
        int a = (n>>i & 1);
        int b = (k>>i & 1);
        if(a == 0 && b == 1) return -1;
        if(a == 1 && b == 0) res+=1;
      }  
      return res;
    }
};
int main(){
    int n,k;
    cin>>n>>k;

    Solution solution;
    int result = solution.minChange(n,k);
    cout<<result;
    return 0;
}