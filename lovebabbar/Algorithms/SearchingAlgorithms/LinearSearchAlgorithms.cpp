#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int N, int x) 
{ 
    for (int i = 0; i < N; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 

int main() 
{ 
    int N;

    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int x;

    cout << "Enter the element to search: ";
    cin >> x;

    int result = search(arr, N, x); 
    (result == -1) 
        ? cout << "Element is not present in the array\n" 
        : cout << "Element is present at index " << result << "\n"; 

    return 0; 
}
