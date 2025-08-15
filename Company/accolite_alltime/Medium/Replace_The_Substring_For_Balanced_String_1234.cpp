#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int balancedString(string s)
    {
        unordered_map<char, int> freq;
        int n = s.size();
        int idealCount = n / 4;

        // Count frequencies of each character
        for (char c : s)
            freq[c]++;

        // Check if already balanced
        if (freq['Q'] <= idealCount && freq['W'] <= idealCount &&
            freq['E'] <= idealCount && freq['R'] <= idealCount)
            return 0;

        int minLength = n;
        int left = 0;

        // Sliding window to find minimum substring
        for (int right = 0; right < n; ++right)
        {
            freq[s[right]]--;
            while (freq['Q'] <= idealCount && freq['W'] <= idealCount &&
                   freq['E'] <= idealCount && freq['R'] <= idealCount)
            {
                minLength = min(minLength, right - left + 1);
                freq[s[left]]++;
                left++;
            }
        }
        return minLength;
    }
};

int main()
{
    string s;
    getline(cin, s);

    Solution solution;
    int result = solution.balancedString(s);
    cout << result;

    return 0;
}