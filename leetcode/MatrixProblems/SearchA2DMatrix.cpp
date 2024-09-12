#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        if (row == 0)
        {
            return false;
        }
        int col = matrix[0].size();

        int start = 0;
        int end = row * col - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int midElement = matrix[mid / col][mid % col];

            if (midElement == target)
            {
                return true;
            }
            else if (midElement < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n, 0));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    Solution solution;
    bool result = solution.searchMatrix(matrix, target);

    if (result)
    {
        cout << "Target found in the matrix." << endl;
    }
    else
    {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
