#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int totalMoney(int n){
        int week = n/7;
        int remWeek= n%7;
        int totalMoneyWeeks = (28 + 28 +7*(week-1))*week/2;
        int start = week + 1;
        int endDay = week + remWeek;
        int totalMoney =(start+endDay)*remWeek/2;
        return totalMoneyWeeks + totalMoney;

    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.totalMoney(n);
    cout<<result;

    return 0;
}