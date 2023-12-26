#include<iostream>
using namespace std;

const int MAX_ROWS = 100;  
const int MAX_COLS = 100;   

void printSum(int arr[][MAX_COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of elements in row " << i + 1 << ": " << sum << endl;
    }
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

    printSum(arr, row, col);

    return 0;
}
