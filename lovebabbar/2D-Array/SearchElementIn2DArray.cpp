#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][100], int n, int m, int k) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    int arr[n][100]; // Assuming a maximum limit of columns (100), you can adjust it based on your needs
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The entered array is:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int k;
    cout << "Enter the element to search: ";
    cin >> k;

    if(isPresent(arr, n, m, k)) {
        cout << "Present" << endl;
    } else {
        cout << "Not Present" << endl;
    }

    return 0;
}
