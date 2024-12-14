#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void isPrime(int n){
        bool flag = true;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Prime";
        }else{
            cout<<"Not Prime";
        }
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    solution.isPrime(n);

    return 0;
}