#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), comp);
        int ans = 1;
        int temp = v[0].second;

        for (int i = 1; i < n; i++) {
            if (temp < v[i].first) {
                temp = v[i].second;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    Solution sol;
    cout << sol.activitySelection(start, end, n) << endl;

    return 0;
}
