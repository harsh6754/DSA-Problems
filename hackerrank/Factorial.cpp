#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Factorial(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        return n * Factorial(n - 1);
    }
}; 
int main()
{
    int n;
    cin >> n;
    Solution solution;
    int result = solution.Factorial(n);
    cout << result << endl;

    return 0;
}