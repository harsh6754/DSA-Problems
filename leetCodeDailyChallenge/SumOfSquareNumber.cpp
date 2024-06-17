#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {  
            double b = sqrt(c - a * a);      
            if (b == (int)b) {          
                return true;                   
            }
        }
        return false;                         
    }
};
int main(){
    int c;
    cin>>c;

    Solution solution;
    bool result = solution.judgeSquareSum(c);
    cout<<result ? 1 : 0;

    return 0;
}