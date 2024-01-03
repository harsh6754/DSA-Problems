#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int n)
{
    double sqr = sqrt(n);
    if(sqr - floor(sqr) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    if(isPerfectSquare(n))
    {
        cout << n << " is a Perfect Square" << endl;
    }
    else
    {
        cout << n << " is Not a Perfect Square Number" << endl;
    }

    return 0;
}
