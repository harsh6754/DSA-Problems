#include<iostream>
using namespace std;

void Counting(int n )
{
    if(n==0)
    {
        return ;
    }
    cout<<n<<endl;

    Counting(n-1);
}


int main()
{
    int n;
    cin>>n;
    
    Counting(n);
 

    return 0;
}