#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4,3,7,7};

    unordered_map<int, vector<int>> mp;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }

    vector<int> ar(n, 0);

    sort(arr.begin(), arr.end());

    reverse(arr.begin(), arr.end());

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int k = mp[arr[i]];
        int g = ((k - 1) % n) == -1 ? n - 1 : ((k - 1) % n);
        if (ar[((k + 1) % n)] == 0 && ar[g] == 0)
        {
            sum += arr[i];
            ar[k] = 1;
        }
    }

    cout << sum << endl;
    cout<<"[";
    int i=0;
    while (i<n-1)
    {
        if (ar[i] == 1)
        {
            cout << i + 1 << ", ";
        }
        i+=1;
    }
    cout << i+1 << "]"<<endl;
    return 0;
}
