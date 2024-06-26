#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return 0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    Solution solution;
    bool result = solution.isAnagram(s, t);
      if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}