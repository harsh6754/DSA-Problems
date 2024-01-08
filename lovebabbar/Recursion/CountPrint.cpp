#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    cout << endl;
    print(n - 1);
    cout << endl;
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;

    print(n);

    return 0;
}