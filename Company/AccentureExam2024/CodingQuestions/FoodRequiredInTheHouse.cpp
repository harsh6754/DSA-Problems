#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int foodRequiredInTheHouse(int r, int unit, vector<int>& arr) {
        int size = arr.size();
        if (size == 0) {
            return -1;
        }
        int TotalUnitOfFood = r * unit;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        if (sum >= TotalUnitOfFood) {
            return sum - TotalUnitOfFood;
        } else {
            return -1;
        }
    }
};

int main() {
    int r, unit;
    cin >> r >> unit;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.foodRequiredInTheHouse(r, unit, arr);
    cout << result << endl;

    return 0;
}