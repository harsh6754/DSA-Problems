#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinTimeToTravelsAllCity(vector<int> arr, int n) {
    sort(arr.begin(), arr.end());

    int totalTime = 0;

    for (int i = 0; i < n; i++) {
        totalTime += arr[i];
    }

    return totalTime - arr[0];
}

int main() {
    int num;
    cin >> num;

    vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    cout << MinTimeToTravelsAllCity(arr, num);

    return 0;
}
