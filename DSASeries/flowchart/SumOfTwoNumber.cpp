#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sumOfTwoNumber(int a, int b){
        int sum;
        sum = a + b;
        return sum;
    }
};
int main(){
    int a;
    int b;
    cin>>a>>b;

    Solution solution;
    int result = solution.sumOfTwoNumber(a,b);
    cout<<result;
    return 0;
}