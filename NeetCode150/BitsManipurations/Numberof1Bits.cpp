#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:
        int hammingWeight(int n){
            int cnt = 0;
            while(n!=0){
                if(n&1){
                    cnt++;
                }
                n=n>>1;
            }
            return cnt;
        }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.hammingWeight(n);
    cout<<result;

    return 0;
}