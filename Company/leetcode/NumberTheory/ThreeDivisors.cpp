#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isThree(int n){
        int count = 0;
        for(int i = 1;i<=n;i++){
            if(n%i==0){
                count++;
            }
            if(count > 3) return false;
        }
        return count == 3;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    bool result = solution.isThree(n);
    cout<<result ? 1 : 0;

    return 0;
}