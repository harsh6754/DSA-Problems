#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumOneBitOperations(int n){
        int ans = 0;
        while(n>0){
            ans^=n;
            n>>=1;
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.minimumOneBitOperations(n);
    cout<<result;

    return 0;
}