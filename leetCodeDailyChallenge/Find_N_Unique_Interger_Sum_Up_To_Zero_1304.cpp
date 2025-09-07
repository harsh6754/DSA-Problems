#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> sumZero(int n){
        vector<int> result;
        if(n % 2 == 1){
            result.push_back(0);
            n--;
        }
        for(int i = 1; i <= n/2; i++){
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};
int main(){
    int n;
    cin>>n;
    
    Solution solution;
    vector<int> result = solution.sumZero(n);
    for(int num : result){
        cout<<num<<" ";
    }
    return 0;
}