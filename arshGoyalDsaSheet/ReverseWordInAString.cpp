#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int start = 0;

        reverse(s.begin(), s.end());

        // Skip leading spaces
        while (start < s.length() && s[start] == ' ')
        {
            start++;
        }

        for (int end = start; end < s.length(); end++)
        {
            if (s[end] == ' ')
            {
                reverse(s.begin() + start, s.begin() + end);
                if (!res.empty())
                    res.append(" ");
                res.append(s.substr(start, end - start));
                // Skip multiple spaces
                while (end < s.length() && s[end] == ' ')
                {
                    end++;
                }
                start = end;
            }
        }

        // Reverse the last word
        reverse(s.begin() + start, s.end());
        if (!res.empty())
            res.append(" ");
        res.append(s.substr(start, s.length() - start));
        if(res[res.size() - 1] == ' '){
            res.pop_back();
        }

        return res;
    }
};

int main() {
    string s;
    cout << "Enter the String: ";
    getline(cin, s);

    Solution solution;
    string result = solution.reverseWords(s);
    cout << "Reversed Words: " << result << endl;

    return 0;
}
