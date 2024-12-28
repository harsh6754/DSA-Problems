#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void MinMaxElement(vector<int>& arr) {
        int size = arr.size();
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        
        int minimum = arr[0];
        int maximum = arr[0];
        
        // Iterate through the array to find min and max
        for (int i = 1; i < size; i++) {
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
            if (arr[i] < minimum) {
                minimum = arr[i];
            }
        }

        // Print the results
        cout << "Minimum: " << minimum << endl;
        cout << "Maximum: " << maximum << endl;
    }
};

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input size." << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    solution.MinMaxElement(arr);

    return 0;
}
