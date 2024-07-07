#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSatisfied(vector<int>&customers, vector<int>&grumpy, int minutes){
        int res = 0, curr = 0;
        for(int i = 0; i < customers.size(); ++i) {
            if(grumpy[i] == 0) res += customers[i];
        }
        
        for(int i = 0; i < minutes; ++i) {
            if(grumpy[i]) curr += customers[i];
        }

        int addi = curr;
        for(int i = minutes; i < customers.size(); ++i) {
            if(grumpy[i - minutes]) curr -= customers[i - minutes];
            if(grumpy[i]) curr += customers[i];
            addi = max(addi, curr);
        }

        return res + addi;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>customers(n),grumpy(n);
    for(int i = 0;i<n;i++){
        cin>>customers[i];
    }
    for(int i = 0;i<n;i++){
        cin>>grumpy[i];
    }

    int minutes;
    cin>>minutes;

    Solution solution;
    int result = solution.maxSatisfied(customers,grumpy,minutes);
    cout<<result;

    return 0;
}