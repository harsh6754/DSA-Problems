#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubArraySum(vector<int> &arr)
    {
        long long maxSum = LLONG_MIN, currentSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            currentSum += arr[i];
            if (currentSum > maxSum)
                maxSum = currentSum;
            if (currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
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
    long long result = solution.maxSubArraySum(arr);
    cout << result;
    return 0;
}
