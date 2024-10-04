#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if (a.first.second == b.first.second) {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < N; i++) {
            v.push_back({{S[i], F[i]}, i + 1});
        }

        sort(v.begin(), v.end(), cmp);

        int ansEnd = v[0].first.second;
        vector<int> ans;
        ans.push_back(v[0].second);

        for (int j = 1; j < N; j++) {
            if (v[j].first.first > ansEnd) {
                ans.push_back(v[j].second);
                ansEnd = v[j].first.second;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> S(N), F(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    Solution solution;
    vector<int> result = solution.maxMeetings(N, S, F);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
