#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void dfs(int curr, int n)
    {
        if (curr > n)
            return;
        res.push_back(curr);
        for (int i = 0; i <= 9; i++)
        {
            if (curr * 10 + i > n)
                return;
            dfs(curr * 10 + i, n);
        }
    }

    vector<int> lexicalOrder(int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, n);
        }
        return res;
    }
};

int main()
{
    int n=10;
    // cout << "Enter the value of n: ";
    // cin >> n;

    Solution solution;
    vector<int> result = solution.lexicalOrder(n);

    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
