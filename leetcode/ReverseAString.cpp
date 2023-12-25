#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {

            std::swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

int main()
{
    Solution solution;

    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    vector<char> charVector(input.begin(), input.end());

    solution.reverseString(charVector);

    cout << "Reversed string: ";
    for (char c : charVector)
    {
        cout << c;
    }

    return 0;
}
