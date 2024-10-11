#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& deadline, vector<int>& profit) {
        int N = deadline.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < N; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.begin(), jobs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first; 
        });
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline + 1, -1);

        int maxProfit = 0;
        for (int i = 0; i < N; i++) {
            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;
            for (int j = currDeadline; j > 0; j--) {
                if (slots[j] == -1) {  
                    slots[j] = i;       
                    maxProfit += currProfit;   
                    break;
                }
            }
        }

        return maxProfit;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> deadline(N);
    for (int i = 0; i < N; i++) {
        cin >> deadline[i];
    }

    vector<int> profit(N);
    for (int i = 0; i < N; i++) {
        cin >> profit[i];
    }

    Solution solution;
    int result = solution.maxProfit(deadline, profit);
    cout << result << endl;

    return 0;
}
