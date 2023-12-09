#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getTripletsWithSum(vector<int> arr, int n, int x) {
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == x) {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the Array Size: ";
    cin >> n;

    int x;
    cout << "Enter the Target Value: ";
    cin >> x;

    vector<int> arr(n);

    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> triplets = getTripletsWithSum(arr, n, x);

    cout << "Triplets with sum " << x << " are:" << endl;
    for (auto triplet : triplets) {
        cout << "(" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << ") ";
    }
    cout << endl;

    return 0;
}
