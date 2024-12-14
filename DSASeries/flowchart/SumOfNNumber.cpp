#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int Sum(int n){
        int sum = 0;
        for(int i = 1;i<=n;i++){
            sum+=i;
        }
        return sum;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.Sum(n);
    cout<<result;

    return 0;
}