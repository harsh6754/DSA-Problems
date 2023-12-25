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
        char ch = 'A'+row-1;
        while(col<=n){
            cout<< ch <<" ";
            
            col+=1;
        }
        cout<<endl;
        row+=1;
    }
}