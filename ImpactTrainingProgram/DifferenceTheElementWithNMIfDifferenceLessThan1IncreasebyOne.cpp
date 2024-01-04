#include<bits/stdc++.h>
using namespace std;

void CompareAndPrint(vector<int>& arr, int p, int q) {
    int N = arr.size();
    for (int i = 0; i < N; i++) {
        if (abs(p - arr[i]) < q) {
            arr[i]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p, q;
    cin >> p >> q;

    CompareAndPrint(arr, p, q);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
