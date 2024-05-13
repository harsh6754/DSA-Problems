#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 3; i < n + 1; ++i) {
            for (int j = 2; j < i - 1; ++j) {
                dp[i] = max(dp[i], dp[j - 1] * (i - j));
            }
        }
        return dp[n];
    }
};

int main(){
    int n;
    cin>>n;
    Solution solution;
    int result = solution.maxA(n);
    cout<<result;

    return 0;
}