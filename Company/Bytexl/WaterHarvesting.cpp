#include <bits/stdc++.h>
using namespace std;
int maxWater(int arr[])
{
    int n = 4;
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

int main()
{
    int arr[] = {7,4,0,9};

    cout << maxWater(arr);

    return 0;
}
