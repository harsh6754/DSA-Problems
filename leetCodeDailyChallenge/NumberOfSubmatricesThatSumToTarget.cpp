#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        if (rows < 1) {
            return 0;
        }

        // Calculate prefix sum for rows
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        int count = 0, sum;
        unordered_map<int, int> counter;
        for (int colstart = 0; colstart < cols; colstart++) {
            for (int col = colstart; col < cols; col++) {
                counter.clear();
                counter[0] = 1;
                sum = 0;
                for (int row = 0; row < rows; row++) {
                    sum += matrix[row][col] - (colstart > 0 ? matrix[row][colstart - 1] : 0);
                    count += counter[sum - target];
                    counter[sum]++;
                }
            }
        }
        return count;
    }
};

int main() {
    int rows, cols, target;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    int result = solution.numSubmatrixSumTarget(matrix, target);
    cout << "Number of submatrices with sum equal to target: " << result << endl;

    return 0;
}
