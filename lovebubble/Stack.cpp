#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> s;
    s.push("harsh");
    s.push("kumar");
    s.push("agrawal");

    cout<<"top element "<<s.top()<<endl;
    s.pop();
    cout<<"top element "<<s.top()<<endl;
    cout<<"size of element "<<s.size()<<endl;
}