#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int minCostToRepairEdges(int n, vector<vector<int>>& edges, vector<vector<int>>& edgesToRepair) {
    unordered_set<string> brokenEdges;
    for (auto& e : edgesToRepair) {
        brokenEdges.insert(to_string(e[0]) + "-" + to_string(e[1]));
    }
    
    DSU dsu(n);
    for (auto& e : edges) {
        if (brokenEdges.find(to_string(e[0]) + "-" + to_string(e[1])) == brokenEdges.end()) {
            dsu.unite(e[0], e[1]);
        }
    }
    
    sort(edgesToRepair.begin(), edgesToRepair.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });
    
    int cost = 0;
    for (auto& e : edgesToRepair) {
        if (dsu.unite(e[0], e[1])) {
            cost += e[2];
        }
    }
    
    return cost;
}

int main() {
    int n, m, r;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of existing edges: ";
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << "Enter number of edges to repair: ";
    cin >> r;
    vector<vector<int>> edgesToRepair(r, vector<int>(3));
    cout << "Enter the edges to repair (u v cost):\n";
    for (int i = 0; i < r; i++) {
        cin >> edgesToRepair[i][0] >> edgesToRepair[i][1] >> edgesToRepair[i][2];
    }
    
    int result = minCostToRepairEdges(n, edges, edgesToRepair);
    cout << "Minimum cost to repair edges: " << result << endl;
    return 0;
}
