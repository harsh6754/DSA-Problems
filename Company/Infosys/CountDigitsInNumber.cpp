#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int count = 0;
    int countDigits(int n){
        if(n == 0){
            return 1;
        }
        while(n > 0){
            count+=1;
            n = n / 10;  
        }
        return count;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.countDigits(n);

    cout<<result<<endl;

    return 0;
}