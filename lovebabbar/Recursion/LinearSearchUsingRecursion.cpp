#include <bits/stdc++.h>
using namespace std;

int linearsearch(int arr[], int n ,int key)
{
    if (n == 0) {
        return -1;
    }
    else if (arr[n - 1] == key) {
        return n - 1;
    }
    return linearsearch(arr, n - 1, key);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    };
    int key;
    cin>>key;
    int ans = linearsearch(arr,n, key);
    if (ans == -1) {
        cout << "The element " << key << " is not found."
             << endl;
    }
    else {
        cout << "The element " << key << " is found at "
             << ans << " index of the given array." << endl;
    }
    return 0;
}