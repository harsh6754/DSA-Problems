#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(vector<int>& coin, int x){
        int size = coin.size();
        if(x == 0) return 0;
        if(x < 0) return INT_MAX;

        int mini = INT_MAX;
        for(int i = 0;i<size;i++){
            int rlt = solve(coin,x-coin[i]);
            if(rlt != INT_MAX) mini= min(mini,1+rlt);
        }
         return mini;
    }

    int minNumberOfCoin(vector<int>& coin, int x){
        int ans = solve(coin,x);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>coin(n);
    for(int i = 0;i<n;i++){
        cin>>coin[i];
    }

    int x;
    cin>>x;

    Solution solution;
    int result = solution.minNumberOfCoin(coin,x);
    cout<<result;

    return 0;
}