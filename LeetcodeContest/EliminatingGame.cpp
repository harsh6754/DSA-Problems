#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
        return 1;
        int ord =1;
        int ans=1;
        int remain =n;
        bool left =0;
        while(remain>1){
            if(left==0 || remain%2 ==1 ){
                ans = ans + ord;
                }

                ord = ord*2;
                remain= remain/2;
                left = !left;
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.lastRemaining(n);
    cout<<result;


    return 0;
}
