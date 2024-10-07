#include <bits/stdc++.h>

using namespace std;

int minCost(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    int res = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the number of ropes: ";
    cin >> n;

    int arr[n];
    cout << "Enter the lengths of the ropes (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minCostValue = minCost(arr, n);

    cout << "Total cost for connecting ropes is " << minCostValue << endl;

    return 0;
}