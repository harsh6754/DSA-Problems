#include <bits/stdc++.h>
using namespace std;
void reverse(string &str, int i, int j)
{

    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str,i, j);
}

int main()
{
    string str;
    cin >> str;

    reverse(str, 0, str.length() - 1);
    cout<<str;

    return 0;
}