#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i = 0;i<n;i++){
        cin>>prices[i];
    }

    solution solution;
    int result = solution.maxProfit(prices);
    cout<<result<<endl;     

    return 0;
}