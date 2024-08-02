#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countSeniors(vector<string>&details){
    int ans = 0;
    for(auto& x : details){
        int age = stoi(x.substr(11,2));
        ans+=age>60;
    }
    return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<string>details(n);
    for(int i = 0;i<n;i++){
        cin>>details[i];
    }
    Solution solution;
    int result = solution.countSeniors(details);
    cout<<result;
    return 0;
}