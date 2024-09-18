#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int rangeBitwiseAnd(int left, int right){
        while(left<right){
            right = right & (right-1);
        }
        return right;
    }
};
int main(){
    int left,right;
    cin>>left>>right;

    Solution solution;
    int result = solution.rangeBitwiseAnd(left,right);
    cout<<result;

    return 0;
}