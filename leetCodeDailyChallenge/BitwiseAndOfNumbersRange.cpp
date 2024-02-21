#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int cnt = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

int main()
{
    int left;
    int right;

    cin>>left>>right;

    Solution solution;
    int result = solution.rangeBitwiseAnd(left, right);
    cout << result;

    return 0;
}