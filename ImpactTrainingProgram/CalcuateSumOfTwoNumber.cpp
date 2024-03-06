#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int sum(int a, int b)
    {
        int ans = a + b;
        return ans;
    }
};
int main()
{
    short a, b;
    cin >> a >> b;

    Solution solution;
    int result = solution.sum(a, b);

    cout <<"Sum of Two Number "<< result;

    return 0;
}
