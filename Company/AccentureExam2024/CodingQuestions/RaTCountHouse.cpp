#include <iostream>
#include <vector>
using namespace std;

int findHouses(int r, int unit, int n, vector<int> &arr) {
    // Edge cases
    if (arr.empty()) return -1; // Return -1 if the array is null
    if (r <= 0 || unit <= 0 || n <= 0) return -1; // Invalid inputs
    
    int totalFoodRequired = r * unit; // Total food required
    int currentFood = 0;
    
    for (int i = 0; i < n; ++i) {
        currentFood += arr[i];
        if (currentFood >= totalFoodRequired) {
            return i + 1; // Return the number of houses
        }
    }
    
    return 0; // If food in all houses is insufficient
}

int main() {
    int r, unit, n;
    cout << "Enter the number of rats (r): ";
    cin >> r;
    cout << "Enter the food unit required per rat (unit): ";
    cin >> unit;
    cout << "Enter the number of houses (n): ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the amount of food in each house: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = findHouses(r, unit, n, arr);
    if (result == -1) {
        cout << "Invalid input or array is null." << endl;
    } else if (result == 0) {
        cout << "0 (Total amount of food is insufficient for all rats)." << endl;
    } else {
        cout << "The minimum number of houses required: " << result << endl;
    }
    
    return 0;
}
