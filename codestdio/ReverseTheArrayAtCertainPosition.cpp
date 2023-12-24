#include<bits/stdc++.h>
using namespace std;

vector<int> ReverseArray(vector<int>& arr, int n,int m)
{
    int start = m;
    int end = n - 1;

    while(start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return arr;
}

void print(vector<int> arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main()
{
    int n;
    cout << "Enter the Size of Array" << endl;
    cin >> n;

    int m;
    cout<<"Enter A position To Reverse The Array"<<endl;
    cin>>m;

    vector<int> arr(n);
    cout << "Enter the array Element" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = ReverseArray(arr, n,m);
    print(ans, n);

    return 0;
}
