//Given Inetrger Sum of Interger

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int IntergerSum(int n){
        int sum = 0;
        while(n!=0){
            sum = sum + n%10;
            n = n/10;
        }
        return sum;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.IntergerSum(n);
    cout<<result;

    return 0;
}