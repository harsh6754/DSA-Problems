#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int solve(int n, int k, int m, vector<int> defaulters, vector<vector<int>> friends) {
    unordered_set<int> defaulters_set(defaulters.begin(), defaulters.end());
    vector<vector<int>> adj(n + 1);
    for (const auto &f : friends) {
        adj[f[0]].push_back(f[1]);
        adj[f[1]].push_back(f[0]);
    }

    vector<bool> visited(n + 1, false);
    int friendships_to_break = 0;

    for (int defaulter : defaulters) {
        if (visited[defaulter]) continue;

        queue<int> q;
        q.push(defaulter);
        visited[defaulter] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int friend_id : adj[node]) {
                if (!visited[friend_id]) {
                    if (!defaulters_set.count(friend_id)) {
                        friendships_to_break++;
                    } else {
                        q.push(friend_id);
                        visited[friend_id] = true;
                    }
                }
            }
        }
    }

    return friendships_to_break;
}

int main() {
    int n = 3, k = 1, m = 3;
    vector<int> defaulters = {2};
    vector<vector<int>> friends = {{2, 1}, {1, 3}, {2, 3}};
    
    cout << solve(n, k, m, defaulters, friends) << endl;
    return 0;
}