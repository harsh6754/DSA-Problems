#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void NumberIsPNZ(int n){
        if(n>0){
            cout<<"Positive";
        }else if(n<0){
            cout<<"Negative";
        }else{
            cout<<"Zero";
        }
    }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    solution.NumberIsPNZ(n);

    return 0;
}