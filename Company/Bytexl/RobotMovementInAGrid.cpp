#include<bits/stdc++.h>
using namespace std;

tuple<int, int> final_position(string grid, int rows, int cols, vector<pair<int, int>>& obstacles) {
    int x = 0, y = 0; 
    for (char move : grid) {
        if (move == 'U' && y < rows - 1 && find(obstacles.begin(), obstacles.end(), make_pair(x, y + 1)) == obstacles.end()) {
            y += 1;
        } else if (move == 'D' && y > 0 && find(obstacles.begin(), obstacles.end(), make_pair(x, y - 1)) == obstacles.end()) {
            y -= 1;
        } else if (move == 'L' && x > 0 && find(obstacles.begin(), obstacles.end(), make_pair(x - 1, y)) == obstacles.end()) {
            x -= 1;
        } else if (move == 'R' && x < cols - 1 && find(obstacles.begin(), obstacles.end(), make_pair(x + 1, y)) == obstacles.end()) {
            x += 1;
        } else if (move == 'X') {
            continue;  
        }
    }
    return make_tuple(x, y);
}

int main() {
    string grid;
    int rows, cols;
    vector<pair<int, int>> obstacles;

    cin >> grid;
    cin >> rows ;
    cin >> cols;

    int obstacle_count;
    cin >> obstacle_count;
    for (int i = 0; i < obstacle_count; ++i) {
        int row, col;
        cin >> row >> col;
        obstacles.push_back(make_pair(row, col));
    }

    tuple<int, int> final_pos = final_position(grid, rows, cols, obstacles);
    cout << "Final position of the robot: (" << get<0>(final_pos) << ", " << get<1>(final_pos) << ")" << endl;

    return 0;
}