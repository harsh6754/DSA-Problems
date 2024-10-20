#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> memberId, int m, vector<vector<int>> friends, int k) {
    unordered_map<int, vector<int>> graph;
    queue<int> q;
    int level = 0;

    // Build the graph
    for (int i = 0; i < m; i++) {
        int x = friends[i][0];
        int y = friends[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Start BFS from the React expert
    q.push(k);
    unordered_set<int> visited;
    visited.insert(k);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (visited.count(neighbor) == 0) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        level++;
    }

    return level - 1; // Subtract 1 to account for the initial level of the React expert
}

int main() {
    int n;
    cin >> n;
    vector<int> memberId(n);
    for (int i = 0; i < n; i++) {
        cin >> memberId[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> friends(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> friends[i][0] >> friends[i][1];
    }
    int k;
    cin >> k;
    int result = solve(n, memberId, m, friends, k);
    cout << result << endl;
    return 0;
}