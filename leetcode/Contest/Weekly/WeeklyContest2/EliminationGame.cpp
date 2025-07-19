#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lastRemaining(int n){
        int head = 1;
        int step = 1;
        bool leftToRight = true;
        while(n > 1){
            if(leftToRight || n%2 ==1){
                head+=step;
            }
            step*=2;
            n/=2;
            leftToRight =!leftToRight;
        }
        return head;
    }
};
int main(){
    int n=9
    ;
    // cin>>n;

    Solution solution;
    int result = solution.lastRemaining(n);
    cout<<result<<endl;
    return 0;
}