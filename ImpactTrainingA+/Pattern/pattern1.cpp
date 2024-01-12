#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;

    int rows=1;
    while(rows<=n){
        int columns=1;
        while(columns<=rows){
            cout<<"*"<<" ";
            columns=columns+1;
        }
        cout<<endl;
        rows+=1;
    }
}