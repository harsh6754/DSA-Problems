#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int MinimumLength(string s){
        string ans = "";
        for(char& c : s){
            if((c=='B' && ans.back() == 'A') || (c=='D' && ans.back() == 'C')){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans.size();
    }
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    int result = solution.MinimumLength(s);
    cout<<result;

    return 0;
}