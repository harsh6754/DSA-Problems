
#include<iostream>
using namespace std;

int getMax(int& a,int& b){
    return (a>b) ?a:b;
}
int main()
{
    int ans = 0;
    int a=0;
    int b = 2;
    ans = getMax(a,b);
    cout<<ans<<endl;

    return 0;
}