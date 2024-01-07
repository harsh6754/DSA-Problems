#include <bits/stdc++.h>
using namespace std;

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
    cout << *(p) << endl;
    cout << *(p + 1) << endl;
    cout << p + (*p) << endl;
}

void update(int *p)
{
    // p = p + 1;
    // *p = *p+1;
    // cout<<p<<endl;
    // cout<<*(p+1)<<endl;
    // cout<<*p<<endl;
    // cout<<*(p)<<endl;
    *p = *p + 1;
    cout << p << endl;
    cout << *(p + 1) << endl;
    cout << *p << endl;
    cout << *(p) << endl;
}

int main()
{
    int value;
    cin >> value;

    int *p = &value;
    print(p);
    cout << endl;
    update(p);

    return 0;
}