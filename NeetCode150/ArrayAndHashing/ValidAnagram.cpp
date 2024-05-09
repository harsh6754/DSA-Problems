#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return 0;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
int main()
{
    string s;
    string t;

    cin >> s >> t;

    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << result;
    if (!result)
    {
        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}