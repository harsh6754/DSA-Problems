#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    double myPow(double x, int n){
        if(n == 0){
            return 1.0;
        }

        double half = myPow(x, n/2);

        if(n % 2 == 0){
            return half * half;
        } else {
            if(n > 0){
                return half * half * x;
            } else {
                return half * half / x;
            }
        }
    }
};
int main(){
    double x;
    cin>>x;

    int n;
    cin>>n;

    Solution solution;
    double result = solution.myPow(x,n);
    cout<< result << endl;

    return 0;
}