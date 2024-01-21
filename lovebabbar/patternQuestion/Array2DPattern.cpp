#include <iostream>
using namespace std;

void printSpiral(int rows, int cols) {
    int matrix[rows][cols];

    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    int counter = 01;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i)
            matrix[top][i] = counter++;

        ++top;

        for (int i = top; i <= bottom; ++i)
            matrix[i][right] = counter++;

        --right;

        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = counter++;

            --bottom;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = counter++;

            ++left;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << "\t";

        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    printSpiral(rows, cols);

    return 0;
}