#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"Size of Stack Is: "<<s.size()<<endl;

    s.pop();
    cout<<"Size of Stack is :"<<s.size()<<endl;

    cout<<"Top element is "<<s.top()<<endl;

    if(s.empty()){
       cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"DStack is not empty"<<endl;
    }

    cout<<"Size of Stack  "<<s.size()<<endl;
    return 0;
}