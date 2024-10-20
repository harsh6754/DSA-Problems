int solve(int n, vector<int> memberId, int m, vector<vector<int>> friends) {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    // Build the graph
    for (int i = 0; i < m; i++) {
        int x = friends[i][0];
        int y = friends[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (visited.find(memberId[i]) == visited.end()) {
            // Perform DFS to explore the connected component
            stack<int> s;
            s.push(memberId[i]);
            visited.insert(memberId[i]);
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                for (int neighbor : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            count++;
        }
    }

    return count;
}