#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 3, 7, 7};

    unordered_map<int, int> mp;

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
        int g = ((k - 1) % n + n) % n; // Adjusted calculation for g

        if (ar[(k + 1) % n] == 0 && ar[g] == 0)
        {
            sum += arr[i];
            ar[k] = 1;
        }
    }

    cout << sum << endl;
    cout << "[";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == 1)
        {
            cout << i + 1;
            count++;
            if (count < sum)
                cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
