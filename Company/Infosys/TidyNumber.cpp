#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isTidyNumber(int input){
        int prevDigit = 10;
        while(input > 0){
            int currDigit = input %10;
            if(currDigit > prevDigit){
                return false;
            } else {
                prevDigit = currDigit;
                input /= 10;
            }
        }
        return true;
    }
};
int main(){
    int input;
    cin>>n;

    Solution solution;
    bool result = solution.isTidyNumber(input);
    cout<<result ? 1 : 0<<endl;
    return 0;
}