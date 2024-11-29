#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int SumOfTheNumberDivisibleBY3And5(int m, int n){
        int sum = 0;
        for(int i = m;i<=n;i++){
            if(i%3==0 && i%5==0){
                sum+=i;
            }
        }
        return sum;
    }
};
int main(){
    int m,n;
    cin>>m>>n;

    Solution solution;
    int result = solution.SumOfTheNumberDivisibleBY3And5(m,n);
    cout<<result<<endl;

    return 0;
}