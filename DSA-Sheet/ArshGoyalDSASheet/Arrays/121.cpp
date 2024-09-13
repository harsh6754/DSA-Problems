#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxProfit(vector<int>&prices){
    if(prices.empty()){
        return 0;
    }
    int minPrices = prices[0];
    int maxProfit = 0;

    for(int i = 1;i<prices.size();i++){
        maxProfit = max(maxProfit,prices[i] - minPrices);
        minPrices = min(minPrices, prices[i]);
    }
    return maxProfit;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i = 0;i<n;i++){
        cin>>prices[i];
    }
    Solution solution;
    int result = solution.maxProfit(prices);
    cout<<result;
    return 0;
}