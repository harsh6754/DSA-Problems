#include<bits/stdc++.h>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int LargestRowSum(int arr[][MAX_COLS], int row, int col) {
    int maxi = INT_MIN;
    int num = -1;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += arr[i][j];
        }

        if (sum > maxi) {
            maxi = sum;
            num = j;  // Assign the current row index to 'num'
        }
    }
    cout << "Maximum sum is " << maxi << endl;
    return num;  // Return the row index with the maximum sum
}

int main() {
    int row, col;

    cout << "Enter number of Rows in Array (1-" << MAX_ROWS << "): ";
    cin >> row;

    cout << "Enter number of Columns in Array (1-" << MAX_COLS << "): ";
    cin >> col;

    if (row <= 0 || row > MAX_ROWS || col <= 0 || col > MAX_COLS) {
        cout << "Invalid input for rows or columns. Exiting program." << endl;
        return 1;
    }

    int arr[MAX_ROWS][MAX_COLS];

    cout << "Enter The 2D Array Elements:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Printing 2D Array:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Max Row Sum at Index " << LargestRowSum(arr, row, col) << endl;

    return 0;
}
