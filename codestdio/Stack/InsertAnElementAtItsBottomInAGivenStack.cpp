#include<bits/stdc++.h>
using namespace std;

void insertToBottom(stack<int>st,int n)
{
    stack<int>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(n);
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    while(!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(8);
    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int n = 7;
    insertToBottom(st,n);

    return 0;
}