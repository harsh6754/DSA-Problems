#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &Profits, vector<int> &Capital)
    {
        int n = Profits.size();
        vector<pair<int, int>> projects(n);

        for (int i = 0; i < n; ++i)
        {
            projects[i] = {Capital[i], Profits[i]};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap(projects.begin(), projects.end());
        priority_queue<int> maxProfitHeap;

        int currentCapital = w;

        for (int i = 0; i < k; ++i)
        {
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= currentCapital)
            {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            if (maxProfitHeap.empty())
            {
                break;
            }
            currentCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return currentCapital;
    }
};
int main()
{
    Solution solution;
    int k;
    cout << "Maximum number of project you can start : ";
    cin >> k;

    int w;
    cout << "Initial Project";
    cin >> w;

    int n;
    cout << "Number of Profit & Capital";
    cin >> n;

    vector<int> Profits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Profits[i];
    }

    vector<int> capital(n);
    for (int i = 0; i < n; i++)
    {
        cin >> capital[i];
    }

    int result = solution.findMaximizedCapital(k, w, Profits, capital);
    cout << "Maximized Capital : " << result;

    return 0;
}