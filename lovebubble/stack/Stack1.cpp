#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;

    s.push(2);
    s.push(3);
    s.push(6);

    s.pop();

    cout<<"Print the Element:-"<<s.top()<< endl;
    if(s.empty()){
        cout<<"Stack Is Empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Size of stack is "<<s.size()<<endl;
}

