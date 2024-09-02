#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        
        for (int i = 1; i < cols; ++i) {
            dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0;
        }
        
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
        }
        
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> obstacleGrid(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> obstacleGrid[i][j];
        }
    }
    
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    
    return 0;
}