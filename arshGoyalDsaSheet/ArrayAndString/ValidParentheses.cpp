#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ; 
        for (int i = 0 ;  i< s.length() ; i++)
        {
            char ch = s[i];


            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch) ; 
            }

            else {

                if (!st.empty())
                {
                    char top = st.top() ;
                    if ((ch == ')' && top == '(') || 
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) 
                        {
            
                            st.pop() ;
                        }
                        else 
                        {
                            return false ; 
                        }
                }
                else 
                {

                    return false ;
                }
            }
        }

 
        if (st.empty())
        {
            return true ; 
        }
        return false ;
    }
};
int main()
{
    string str;
    cin>>str;

    Solution solution;
    bool result = solution.isValid(str);
    cout<<result;

    return 0;
}