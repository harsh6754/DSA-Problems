#include<bits/stdc++.h>
using namespace std;

int distinctelement(int arr[], int n)
{
    int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
       if(arr[i] == arr[i+1])
       {
        count += 1;
       }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = distinctelement(arr, n);
    cout << "Number of duplicate elements: " << result << endl;
    return 0;
}
