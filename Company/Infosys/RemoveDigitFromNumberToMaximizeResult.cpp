#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string removeDigit(string n, char digit){
        int idx = -1;
        for(int i = 0;i<n.size();i++){
            if(n[i] == digit){
                idx = i;
                if(i + 1 < n.size() && n[i] < n[i + 1]){
                    break;
                }
            }
        }
        return n.substr(0,idx) + n.substr(idx + 1);
    }
};
int main(){
    string n;
    getline(cin,n);

    char digit;
    cin>>digit;

    Solution solution;
    string result = solution.removeDigit(n,digit);
    cout<<result<<endl;
    return 0;
}