#include <iostream>
using namespace std;

#define N 4

// Function to rotate the matrix 90 degrees clockwise
void rotate90Clockwise(int a[N][N]) {
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            // Swap elements of each cycle in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

// Function to take input for matrix elements from the user
void inputMatrix(int arr[N][N]) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }
}

// Function to print matrix
void printMatrix(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driver code
int main() {
    int arr[N][N];
    inputMatrix(arr);

    rotate90Clockwise(arr);

    cout << "Matrix after 90-degree clockwise rotation:" << endl;
    printMatrix(arr);

    return 0;
}
