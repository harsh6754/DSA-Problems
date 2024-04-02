#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                leftsmall[i] = 0;
            }
            else
            {
                leftsmall[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        int maxarea = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                rightsmall[i] = n - 1;
            }
            else
            {
                rightsmall[i] = st.top() - 1;
            }
            st.push(i);
            maxarea = max(maxarea, (rightsmall[i] - leftsmall[i] + 1) * heights[i]);
        }

        return maxarea;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    Solution solution;
    int result = solution.largestRectangleArea(height);
    cout << result;

    return 0;
}