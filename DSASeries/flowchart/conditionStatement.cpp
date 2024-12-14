#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool condition(int a, int b)
    {
        if (a > b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    int a;
    int b;
    cin >> a >> b;

    Solution solution;
    bool result = solution.condition(a, b);
    cout << result ? "Yes" : "No";

    return 0;
}