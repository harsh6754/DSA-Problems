#include <iostream>
#include <vector>
using namespace std;

int findDivisorIndex(const vector<int>& arr, int divisor) {
    for (int i = 0; i < arr.size(); i++) {
        if (divisor == 0) continue; // Avoid division by zero
        int quotient = arr[i] / divisor;
        int remainder = arr[i] % divisor;

        // Check if the divisor exists in the array
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == divisor) {
                return j; // Return the index if divisor is found
            }
        }
    }
    return -1; // Return -1 if divisor not found
}

int main() {
    vector<int> arr = {10, 5, 15, 20};
    int divisor = 5;

    int index = findDivisorIndex(arr, divisor);
    cout << "Index: " << index << endl;

    return 0;
}
