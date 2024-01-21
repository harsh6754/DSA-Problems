#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int ans = INT_MIN;
        priority_queue<pair<int, int>> maxHeap;

        for (const vector<int> &p : points)
        {
            const int x = p[0];
            const int y = p[1];

            while (!maxHeap.empty() && x - maxHeap.top().second > k)
                maxHeap.pop();

            if (!maxHeap.empty())
                ans = max(ans, x + y + maxHeap.top().first);

            maxHeap.emplace(y - x, x);
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2)); 
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1]; 
    }

    int k;
    cin >> k;

    Solution solution;
    int result = solution.findMaxValueOfEquation(points, k);
    cout << result;

    return 0;
}
