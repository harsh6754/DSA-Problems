#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long len;
};

vector<long long> mazeGame(vector<long long>& t, vector<int>& endpoint1,
                            vector<int>& endpoint2, vector<long long>& edgeLength) {
    int n = t.size();
    int m = endpoint1.size();
    vector<vector<Edge>> g(n);
    
    for (int i = 0; i < m; i++) {
        int u = endpoint1[i] - 1; // 0-based
        int v = endpoint2[i] - 1;
        long long w = edgeLength[i];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, INF);
    dist[0] = 0;
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (d >= t[u]) continue; // can't stay here
        
        for (auto &e : g[u]) {
            long long nd = d + e.len;
            if (nd < dist[e.to] && nd < t[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    
    int m;
    cin >> m;
    vector<int> endpoint1(m), endpoint2(m);
    for (int i = 0; i < m; i++) cin >> endpoint1[i];
    cin >> m; // same m again
    for (int i = 0; i < m; i++) cin >> endpoint2[i];
    cin >> m; // same m again
    vector<long long> edgeLength(m);
    for (int i = 0; i < m; i++) cin >> edgeLength[i];
    
    vector<long long> res = mazeGame(t, endpoint1, endpoint2, edgeLength);
    for (auto x : res) cout << x << "\n";
}
