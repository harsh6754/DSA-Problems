#include<iostream>
using namespace std;

void segregateArray(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // Find the first odd number from the left
        while (arr[left] % 2 == 0 && left < right)
            left++;

        // Find the first even number from the right
        while (arr[right] % 2 != 0 && left < right)
            right--;

        // Swap the found odd and even numbers
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    segregateArray(arr, N);

    cout << "Array after Segregation" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
