#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// A utility function to check if a cell is valid and unblocked
bool isValid(int x, int y, int rows, int cols, vector<string>& grid) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '.');
}

// Function to find the shortest path using BFS
string reachEndInTime(int rows, vector<string>& grid, int maxTime) {
    // Directions for moving in the grid: right, left, down, up
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Queue for BFS that stores pairs of coordinates and current time step
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    
    // Vector to keep track of visited cells
    vector<vector<bool>> visited(rows, vector<bool>(grid[0].size(), false));
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto [pos, time] = q.front();
        q.pop();
        
        int x = pos.first;
        int y = pos.second;
        
        // Check if we have reached the bottom-right corner
        if (x == rows - 1 && y == grid[0].size() - 1) {
            return (time <= maxTime) ? "Yes" : "No";
        }
        
        // Explore all 4 possible directions
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            if (isValid(newX, newY, rows, grid[0].size(), grid) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({{newX, newY}, time + 1});
            }
        }
    }
    
    // If we exhaust the BFS without reaching the end, return "No"
    return "No";
}

int main() {
    int rows;
    cin >> rows;
    vector<string> grid(rows);
    for (int i = 0; i < rows; ++i) {
        cin >> grid[i];
    }
    int maxTime;
    cin >> maxTime;
    
    cout << reachEndInTime(rows, grid, maxTime) << endl;
    
    return 0;
}
