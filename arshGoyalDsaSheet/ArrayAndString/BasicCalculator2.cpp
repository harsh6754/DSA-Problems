#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk; 
        
        long long int ans = 0, curr = 0;
        char sign = '+';  
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0');  
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                
                if(sign == '+') stk.push(curr); 
            
                else if(sign == '-') stk.push(curr*(-1));  
                
                else if(sign == '*'){
                    int num = stk.top(); stk.pop(); 
                    stk.push(num*curr); 
                }
                
                else if(sign == '/'){
                    int num = stk.top();stk.pop(); 
                    stk.push(num/curr);
                }
                
                curr = 0; 
                sign = s[i]; 
            }
            
        }
        
        while(stk.size()){
            ans += stk.top(); stk.pop();
        }
            
        return ans;    
    }
};
int main()
{
    string s;
    cin>>s;

    Solution solution;
    int result = solution.calculate(s);
    cout<<result;

    return 0;
}