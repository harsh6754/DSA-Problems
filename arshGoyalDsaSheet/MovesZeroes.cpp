#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &arr)
    {
        vector<int> temp(arr.size(), 0);
        int k = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
            {
                temp[k++] = arr[i];
            }
        }
        arr = temp;
    }
};

int main()
{
    Solution solution;
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solution.moveZeroes(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
