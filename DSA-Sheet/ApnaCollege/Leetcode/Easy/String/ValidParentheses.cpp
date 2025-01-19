#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValid(string s){
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                if(s[i] == ')' && st.top() != '('){
                    return false;
                }
                if(s[i] == '}' && st.top() != '{'){
                    return false;
                }
                if(s[i] == ']' && st.top() != '['){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    bool result = solution.isValid(s);
    cout<<result ? 1 : 0;

    return 0;
}