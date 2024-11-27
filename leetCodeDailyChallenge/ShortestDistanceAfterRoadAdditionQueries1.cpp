#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n); // Adjacency list representation of the graph
        
        // Initialize the graph with default edges (node i -> node i+1)
        for (int i = 0; i < n - 1; ++i) {
            g[i].push_back(i + 1);
        }

        // BFS function to find shortest distance from node 0 to node n-1
        auto bfs = [&](int start) -> int {
            queue<int> q{{start}};
            vector<bool> vis(n, false); // Visited nodes
            vis[start] = true;
            
            for (int d = 0;; ++d) {
                int sz = q.size();
                while (sz--) {
                    int u = q.front();
                    q.pop();
                    if (u == n - 1) {
                        return d; // Found shortest path
                    }
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        };

        vector<int> ans;
        // Process each query and calculate the shortest distance
        for (const auto& q : queries) {
            g[q[0]].push_back(q[1]); // Add new road (edge)
            ans.push_back(bfs(0));   // Compute shortest distance from node 0 to n-1
        }
        return ans;
    }
};

int main() {
    int n, q;
    cout << "Enter the number of nodes (n): ";
    cin >> n;

    if (n < 2 || n > 1000) {
        cout << "Constraint violated: 2 <= n <= 1000" << endl;
        return 0;
    }

    cout << "Enter the number of queries (q): ";
    cin >> q;

    if (q < 1 || q > 1000) {
        cout << "Constraint violated: 1 <= q <= 1000" << endl;
        return 0;
    }

    vector<vector<int>> queries;
    cout << "Enter the queries (u, v) where a road is added from node u to node v:" << endl;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Constraint violated: 0 <= u, v < n" << endl;
            return 0;
        }

        queries.push_back({u, v});
    }

    // Solve the problem
    Solution sol;
    vector<int> result = sol.shortestDistanceAfterQueries(n, queries);

    // Output the results
    cout << "Shortest distances after each query:" << endl;
    for (int dist : result) {
        cout << dist << endl;
    }

    return 0;
}
