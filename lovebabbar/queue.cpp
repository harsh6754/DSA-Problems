#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string>s;
    s.push("harsh");
    s.push("kumar");
    s.push("agrawal");

    cout<<"size befor pop "<<s.size()<<endl;
    cout<<"top element "<<s.front()<<endl;
    s.pop();
    cout<<"top element "<<s.front()<<endl;
    cout<<"size "<<s.size()<<endl;
}