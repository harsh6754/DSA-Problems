#include<bits/stdc++.h>
using namespace std;
int main()
{

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Front of q is ->"<<" "<<q.front()<<endl;
    cout<<"Back of q is ->"<<" "<<q.back()<<endl;
    
    cout<<"The Size of Queue->"<<q.size()<<endl;

    q.pop();
    q.pop();

     cout<<"Front of q is ->"<<" "<<q.front()<<endl;
     cout<<"Back of q is ->"<<" "<<q.back()<<endl;

     cout<<"The Size of Queue->"<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty "<<endl;
    }

    return 0;

}
