#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount % 10 >= 5) {
            return 100 - (purchaseAmount/10 + 1) * 10;
        }else {
            return 100 - (purchaseAmount / 10 ) * 10;;
        }
    }
};
int main(){
    int purchaseAmount;
    cin>>purchaseAmount;


    Solution solution;
    int result = solution.accountBalanceAfterPurchase(purchaseAmount);
    cout<<result;

    return 0;
}