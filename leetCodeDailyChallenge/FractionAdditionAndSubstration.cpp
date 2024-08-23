#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionAddition(string expression) {
        stringstream iss(expression);
        char _;
        int A=0;
        int B=1;
        int a;
        int b;

        while(iss>>a>>_>>b){
            A=a*B+A*b;
            B*=b;
            int dec=abs(__gcd(A,B));
            A/=dec;
            B/=dec;
        }
        return to_string(A)+"/"+to_string(B);
    }
};
int main(){
    string expression;
    getline(cin,expression);

    Solution solution;
    string result = solution.fractionAddition(expression);
    cout<<result;

    return 0;
}