#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void PrintNumbers(int n){
        for(int i = 1;i<=n;i++){
            cout<<i<<" ";
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