#include <bits/stdc++.h>
using namespace std;

int sumOfArray(int arr[], int n)
{
    if (n <= 0)
        return 0;

    return (sumOfArray(arr, n - 1) + arr[n - 1]);
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = sumOfArray(arr, n);
    cout << result;

    return 0;
}