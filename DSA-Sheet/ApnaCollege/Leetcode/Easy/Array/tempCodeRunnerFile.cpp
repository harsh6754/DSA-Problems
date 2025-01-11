#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxProfit(vector<int>& prices){
        int size = prices.size();
        if(prices.empty()){
            return 0;
        }
        int minPrices = prices[0];
        int maxProfit = 0;
        for(int i = 1;i<size;i++){
            if(prices[i]<minPrices){
                minPrices = prices[i];
            }
            else{
                maxProfit = max(maxProfit,prices[i]-minPrices);
            }
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