#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;

    int row=1;
    while(row<=n){
        int col=1;
        while(col<=row){
            cout<<col<<" ";
            col+=1;
        }
        cout<<endl;
        row+=1;
    }
}