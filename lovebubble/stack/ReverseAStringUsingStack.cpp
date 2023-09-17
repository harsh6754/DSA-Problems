#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string str = "HARSH AGRAWAL";
    stack<char>s;
    for(int i = 0;i<str.length();i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = " ";
    while(!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"Reverse String is :"<<ans<<endl;
    return 0;
    }