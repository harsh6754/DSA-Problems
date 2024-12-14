#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void NumberIsEvenOrOld(int n){
        if(n%2==0){
            cout<<"Number is Even";
        }else{
            cout<<"Number is Old";
        }
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    solution.NumberIsEvenOrOld(n);

    return 0;
}