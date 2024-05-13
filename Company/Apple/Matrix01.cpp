#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void bfs(queue<vector<int>>& q, vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        while (!q.empty()) {
            vector<int> a = q.front();
            q.pop();
            int r = a[0];
            int c = a[1];
            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k][0];
                int nc = c + dir[k][1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && arr[nr][nc] == -1) {
                    arr[nr][nc] = arr[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    void updateMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        queue<vector<int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    q.push({i, j});
                } else {
                    arr[i][j] = -1;
                }
            }
        }

        bfs(q, arr);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    solution.updateMatrix(mat);

    // Output the resulting matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
