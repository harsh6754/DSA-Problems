#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int findComplement(long n){
    for(long i = 1;i<=n;i<<=1){
        n^=i;
    }
    return n;
    }
};
int main(){
    long n;
    cin>>n;

    Solution solution ;
    int result = solution.findComplement(n);
    cout<<result;

    return 0;
}