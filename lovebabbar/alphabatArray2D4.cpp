#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"entere the value of n:"<<endl;
    cin>>n;

    int row=1;
    while(row<=n)
    {
        int col=1;
        char ch ='A' + row + col - 2;
        while(col<=n){
            cout<<ch<<" ";
            ch+=1;
            col+=1;
        }
        cout<<endl;
        row+=1;
    }
}