#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution{
    public:
    int solve (long long n, int i){
        if( i == n ) return 1;
        if( i > n )  return 0;

        return (solve(n,i+1) + solve(n,i+2)) % MOD;
    }

    int countDistinctWayToClimbingStairs(long long n){
         return solve(n,0);
    }
};
int main(){
    long long n;
    cin>>n;

    Solution solution;
    int result = solution.countDistinctWayToClimbingStairs(n);
    cout<<result;

    return 0;
}