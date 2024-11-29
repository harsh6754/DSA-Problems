#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int OperationsChoices(int a, int b, int c){
        if(c == 1){
            return a + b;
        }else if(c == 2){
            return a - b;
        }else if(c == 3){
            return a * b;
        }else if(c == 4){
            return a / b;
        }else{
            return -1;
        }
    }
};
int main(){
    int a,b,c;
    cin>>a>>b>>c;

    Solution solution;
    int result = solution.OperationsChoices(a,b,c);
    cout<<result;

    return 0;
}