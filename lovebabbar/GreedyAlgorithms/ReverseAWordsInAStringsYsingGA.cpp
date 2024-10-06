#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string reverseWords(string S){
        int length = S.length();
        string ans = "";
        string temp = "";

        for(int i = length - 1;i>=0;i--){
            if(S[i] == '.'){
                reverse(temp.begin(),temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp ="";
            }else{
                temp.push_back(S[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        ans = ans + temp;  
        return ans;
    }
};
int main(){
    string S;
    getline(cin,S);

    Solution solution;
    string result = solution.reverseWords(S);
    cout<<result;

    return 0;
}