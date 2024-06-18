#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
     int countValues(int n){
        int unset_bits=0;
        while(n){
            if((n & 1) == 0){
                unset_bits++;
            }
            n=n>>1;
        }
        return 1 << unset_bits;
     }      
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.countValues(n);
    cout<<result;

    return 0;
}