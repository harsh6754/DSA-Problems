#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
    if (n < 3)
    {
        return 0;
    }

    int res = 0;
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res += max(0, min(leftMax[i], rightMax[i]) - arr[i]);
    }

    return res;
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

    cout << maxWater(arr, n);

    return 0;
}
