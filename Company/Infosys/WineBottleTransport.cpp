#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> arr = {5, -4, 1, -3, 1};
    int buy = 0;
    int sell = 0;
    int n = arr.size();
    long long operations = 0;

    while (buy < n && sell < n) {
        while (buy < n && arr[buy] <= 0) {
            buy++;
        }
        while (sell < n && arr[sell] >= 0) {
            sell++;
        }
        if (buy < n && sell < n) {
            if (abs(arr[buy]) >= abs(arr[sell])) {
                operations += abs(buy - sell) * abs(arr[sell]);
                arr[buy] += arr[sell];
                arr[sell] = 0;
            } else {
                operations += abs(buy - sell) * abs(arr[buy]);
                arr[sell] += arr[buy];
                arr[buy] = 0;
            }
        }
    }
    cout << operations << endl;

    return 0;
}