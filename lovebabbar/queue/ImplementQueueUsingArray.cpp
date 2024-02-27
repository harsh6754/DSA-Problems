#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(11);
    q.push(15);
    q.push(13);
    q.push(2);

    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;
    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty"
             << " Having :" << q.size() << " element" << endl;
    }

    cout<<"Front of queue "<<q.front()<<endl;
    cout<<"Last of queue "<<q.back()<<endl;
    return 0;
}