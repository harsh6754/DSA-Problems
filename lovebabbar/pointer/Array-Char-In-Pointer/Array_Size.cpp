#include <bits/stdc++.h>
using namespace std;
int main()
{
    int temp[10];
    cout << sizeof(temp) << endl;
    cout << sizeof(*temp) << endl;
    cout << sizeof(&temp) << endl;

    cout<<endl;

    int *p = &temp[0];
    p = p + 1;
    cout<<p<<endl;
    cout<<*(p+1)<<endl;
    cout<<endl;
    
    cout << *p << endl;

    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(&p) << endl;

    return 0;
}