#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int> > arr, int nRows, int mCols) {
    vector<int> ans;

    for (int col = 0; col < mCols; col++) {
        if (col & 1) {
            // odd Index -> Bottom to top
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // 0 or even index -> top to bottom
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    int nRows, mCols;
    cout << "Enter number of Rows in Array: ";
    cin >> nRows;

    cout << "Enter number of Columns in Array: ";
    cin >> mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));

    cout << "Enter The 2D Array Elements:" << endl;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> result = wavePrint(arr, nRows, mCols);

    cout << "Wave Print of 2D Array:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
