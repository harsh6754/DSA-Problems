#include<iostream>
using namespace std;

void minChocolates(int A[0],int N)
{
    int B[N];
    for(int i  = 0;i<N;i++)
    {
        B[i]=1;
    }
    for(int i = 1 ;i<N;i++)
    {
        if(A[i]>A[i-1])
        B[i] = B[i-1]+1;
        else B[i]=1;
    }
    for(int i = N-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
        B[i]=max(B[i+1]+1,B[i]);
        else
        B[i]=max(B[i],1);
    }
    int sum = 0;
    for(int i = 0;i<N;i++)
    {
        sum+=B[i];
    }
    cout<<sum<<endl;
}


int main()
{

   int A[]={23,25,24,23,21};
   int N= sizeof(A)/sizeof(A[0]);

    minChocolates(A, N);
   return 0;
}