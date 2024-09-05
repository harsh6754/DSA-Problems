#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>missingRolls(vector<int>&rolls,int mean, int n){
        const int targetSum = (rolls.size()+n)*mean;
        int missingSum = targetSum - accumulate(rolls.begin(),rolls.end(),0);
        if(missingSum > n * 6 || missingSum < n){
            return {};
        }
        vector<int> ans(n, missingSum / n);
        missingSum %= n;
        for (int i = 0; i < missingSum; ++i)
            ++ans[i];

        return ans;
    }
};
int main(){
    int ele;
    cin>>ele;
    vector<int>rolls(ele);
    for(int i = 0;i<ele;i++){
        cin>>rolls[i];
    }
    int mean;
    cin>>mean;

    int n;
    cin>>n;

    Solution solution;
    vector<int>result = solution.missingRolls(rolls,mean,n);
    cout<<"[";
    for(auto& ans : result){
        cout<<ans<<" , ";
    }
    cout<<"]";

    return 0;
}