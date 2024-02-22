#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &StockPrice, int n) {
        int Min_Price = StockPrice[0];
        int Max_Price = 0;

        for (int i = 1; i < n; i++) {
            Max_Price = max(Max_Price, StockPrice[i] - Min_Price);
            Min_Price = min(StockPrice[i], Min_Price);
        }
        return Max_Price;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> StockPrice(n);
    for (int i = 0; i < n; i++) {
        cin >> StockPrice[i];
    }

    Solution solution;
    int max_profit = solution.maxProfit(StockPrice, n);
    cout <<max_profit << endl;

    return 0;
}
