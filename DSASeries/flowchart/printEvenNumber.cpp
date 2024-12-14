#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void PrintNumbers(int n){
        for(int i = 2;i<=n;i+=2){
            if(i%2 ==0){
                cout<<i<<" ";
            }
        }
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    solution.PrintNumbers(n);

    return 0;
}