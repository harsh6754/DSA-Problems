#include <iostream>

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
        // int fact = Factorial(n - 1);  // Fix the function name here
        // int fact2 = n * fact;
        // return fact2;  // Fix the return statement here
        return n * Factorial(n-1);
    }
};

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution solution;

    int ans = solution.Factorial(n);
    cout << "Factorial: " << ans << endl;

    return 0;
}
