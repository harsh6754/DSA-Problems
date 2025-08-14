#include <bits/stdc++.h>
using namespace std;

int w, h, n;

int bfs(const vector<int>& offices) {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int,int>> q;
    
    // initialize BFS with offices
    for (int pos : offices) {
        int r = pos / w, c = pos % w;
        dist[r][c] = 0;
        q.push({r, c});
    }
    
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int maxDist = 0;
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                maxDist = max(maxDist, dist[nr][nc]);
                q.push({nr, nc});
            }
        }
    }
    return maxDist;
}

int findMinDistance(int W, int H, int N) {
    w = W; h = H; n = N;
    vector<int> cells(w*h);
    iota(cells.begin(), cells.end(), 0);
    
    int best = INT_MAX;
    vector<bool> choose(w*h, false);
    fill(choose.begin(), choose.begin() + n, true);
    
    do {
        vector<int> offices;
        for (int i = 0; i < w*h; i++) {
            if (choose[i]) offices.push_back(cells[i]);
        }
        best = min(best, bfs(offices));
    } while (prev_permutation(choose.begin(), choose.end()));
    
    return best;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    cout << findMinDistance(W, H, N) << "\n";
}
