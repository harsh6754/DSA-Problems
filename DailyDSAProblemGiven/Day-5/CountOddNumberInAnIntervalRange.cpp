#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countOdds(int low, int high){
        int ans=0;
        for(int i = low;i<=high;i++){
            if(i%2==1){
              ans+=1;
            }
        }
        return ans;
}
};
int main(){
    int low,high;
    cin>>low>>high;

    Solution solution;
    int result = solution.countOdds(low,high);
    cout<<result;
    return 0;
}