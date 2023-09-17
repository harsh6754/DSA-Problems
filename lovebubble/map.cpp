#include<iostream>
#include<map>
using namespace std;
int main()
    {
        map<int , string> m;
        m[1] ="ishita";
        m[2] = "harsh";
        m[13] = "agrawal";

        m.insert({5,"kumar"});

        cout<<"before erase "<<endl;

        for(auto i : m){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<"find -13 -> "<<m.count(-13)<<endl;

         //m.erase(m.begin());
        cout<<"after erase "<<endl;
        for(auto i : m){
            cout<<i.first<<" "<<i.second<<endl;
        }

        auto it = m.find(5);
        for(auto i=it; i!=m.end();i++){
            cout<<(*i).first<<" "<<(*i).second<< endl;
        }
    }