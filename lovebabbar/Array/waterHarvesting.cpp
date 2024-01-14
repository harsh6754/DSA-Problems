#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int waterHarvesting(vector<int> arr) {
    int n = arr.size();

    // Handle cases with fewer than 3 buildings:
    if (n < 3) {
        return 0;
    }

    // Sort the buildings in descending order directly:
    sort(arr.rbegin(), arr.rend());

    int max1 = arr[0];
    int max2 = arr[1];
    int diff = abs(max1 - max2);

    // Handle cases where the two tallest buildings have the same height:
    if (diff == 0) {
        return 0;
    }

    int cap = diff * max2;
    int totalArea = 0;

    // Calculate the total area below the two tallest buildings:
    for (int i = 2 ;i < n; i++) {
        totalArea += arr[i];
    }

    return abs(cap - totalArea);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = waterHarvesting(arr);
    cout << result << endl;

    return 0;
}
