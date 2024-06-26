#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        // int sum = n * ( n + 1)/2;
        // for(int  i = 0;i<n;i++){
        //     sum-=arr[i];
        // }
        // return sum;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (i == arr[i - 1])
            {
                continue;
            }
            else
            {
                return i;
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution solution;
    int result = solution.missingNumber(n, arr);
    cout << result;

    return 0;
}