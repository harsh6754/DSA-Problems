#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int SumOfOldNumber(int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                sum += i;
            }
        }
        return sum;
    }
};
int main()
{
    int n;
    cin >> n;

    Solution solution;
    int result = solution.SumOfOldNumber(n);
    cout << result << endl;
    return 0;
}