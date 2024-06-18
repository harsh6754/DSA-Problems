#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int computeXOR(int n)
    {
        if (n % 4 == 0)
        {
            return n;
        }
        else if (n % 4 == 1)
        {
            return 1;
        }
        else if (n % 4 == 2)
        {
            return n + 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    int n;
    cin >> n;

    Solution solution;
    int result = solution.computeXOR(n);
    cout << result;

    return 0;
}