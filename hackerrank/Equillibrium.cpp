#include<bits/stdc++.h>
using namespace std;

int equilibrium(vector<int> arr, int n) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int leftSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum -= arr[i];

        if (leftSum == totalSum) {
            return i;
        }

        leftSum += arr[i];
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int equilibriumIndex = equilibrium(arr, n);

    if (equilibriumIndex != -1) {
        cout <<  arr[equilibriumIndex] << endl;
    } else {
     return -1;
    }

    return 0;
}
