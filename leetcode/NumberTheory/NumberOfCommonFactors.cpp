#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int commonFactors(int a, int b){
        int count = 0;
        int mini = min(a,b);
        for(int i = 0;i<=mini;i++){
            if(a%i==0 && b%i == 0){
              count+=1;
            }
        }
        return count;
    }
};
int main(){
    int a,b;
    cin>>a>>b;

    Solution solution;
    int result = solution.commonFactors(a,b);
    cout<<result;

    return 0;
}