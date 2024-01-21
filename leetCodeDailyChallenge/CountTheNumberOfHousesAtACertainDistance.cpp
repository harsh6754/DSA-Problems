#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> minDistance(int n, int x, int y) {
    // Initialize an array to store the result
    vector<int> result(n, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // Calculate the minimum distance between houses i and j
            int dist = min({abs(i - j), abs(i - x) + abs(j - y) + 1, abs(i - y) + abs(j - x) + 1});
            
            // Increment the count for the corresponding minimum distance in the result array
            result[dist - 1]++;
        }
    }

    return result;
}

int main() {
    int n, x, y;

    // Input from the user
    cout << "Enter the number of houses (n): ";
    cin >> n;

    cout << "Enter the house number connected by the first street (x): ";
    cin >> x;

    cout << "Enter the house number connected by the second street (y): ";
    cin >> y;

    // Calculate and print the result
    vector<int> result = minDistance(n, x, y);

    cout << "Result: [";
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
