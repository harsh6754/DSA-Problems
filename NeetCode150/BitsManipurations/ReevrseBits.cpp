#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i=0;i<32;++i)res|=((n>>i)&1)<<(31-i);
        return res;
    }
};
int main(){
    uint32_t n;
    cin>>n;

    Solution solution;
    uint32_t result = solution.reverseBits(n);
    cout<<result;

    return 0;
}