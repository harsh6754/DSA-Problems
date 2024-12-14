#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int simpleInterest(int principal, int rate, int time){
        int SimpleInterest = (principal*rate*time)/100;
        return SimpleInterest;
    }
};
int main(){
    int principal;
    int rate;
    int time;
    cin>>principal>>rate>>time;

    Solution solution;
    int result = solution.simpleInterest(principal,rate,time);
    cout<<result;

    return 0;

}