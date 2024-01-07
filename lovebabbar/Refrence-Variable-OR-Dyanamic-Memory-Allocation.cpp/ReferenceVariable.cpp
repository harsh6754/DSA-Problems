#include<bits/stdc++.h>
using namespace std;


void update(int n)
{
    n++;
}
void update2(int &n)
{
    n++;
}
int main()
{
    int i = 5;
    int &j = i;

    cout<<i<<endl;
    cout<<i++<<endl;
    cout<<++i<<endl;
    cout<<++j<<endl;
    cout<<j++<<endl;
    cout<<j<<endl;


    cout<<endl;

int n;
cin>>n;

cout<<endl;

    cout<<n<<endl;
    update(n);
    cout<<n<<endl;

    cout<<endl;
    cout<<n<<endl;
    update2(n);
    cout<<n<<endl;

    return 0;
}