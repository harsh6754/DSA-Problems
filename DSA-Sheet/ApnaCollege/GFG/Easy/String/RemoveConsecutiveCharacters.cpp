#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string removeConsecutiveCharacter(string s){
        string ans = "";
        ans += s[0];
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                ans += s[i];
            }
        }
        return ans;
    }
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    string result = solution.removeConsecutiveCharacter(s);
    cout<<result;

    return 0;
}