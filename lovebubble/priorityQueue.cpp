#include<iostream>
#include<queue>
using namespace std;
int  main()
{
    //max heap
    priority_queue<int>maxi;
    cout<<"maxi element "<<endl;

    maxi.push(1);
    maxi.push(3);
    maxi.push(5);
    maxi.push(0);
    cout<<"size -> "<<maxi.size()<<endl;
    int n = maxi.size();
    for(int i = 0;i<n;i++){
        cout<<maxi.top() <<endl;
        maxi.pop();
    }
    //min heap
    priority_queue<int,vector<int>,greater<int> > mini;

    cout<<"min i element "<<endl;

    mini.push(6);
    mini.push(1);
    mini.push(2);
    mini.push(5);

    cout<<"size -> "<<mini.size()<<endl;
    int m = mini.size();
    for(int i = 0;i<m;i++)
    {
        cout<<mini.top()<<endl;
        mini.pop();
    }
    cout<<"khali hai kya bhai "<<mini.empty()<<endl;
}

