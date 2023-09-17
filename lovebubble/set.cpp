#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(6);
    s.insert(3);
    s.insert(2);
    s.insert(1);

    for(auto i :s){
        cout<<i<<endl;
    }
    cout<<endl;
    s.erase(s.begin());
    for(auto i :s){
        cout<<i<<endl;
    }
    cout<<endl;
    s.erase(s.end());
    for(auto i :s){
        cout<<i<<endl;
    } 
   
cout<<s.count(5)<<endl;
}