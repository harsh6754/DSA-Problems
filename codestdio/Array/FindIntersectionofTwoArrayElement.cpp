#include<bits/stdc++.h>
using namespace std;

vector<int> FindIntersectionOfTwoArray(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    int n, m;

    cout << "Enter the First Array Size" << endl;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter The Second Array Size" << endl;
    cin >> m;

    vector<int> arr2(m);  // Fix: Use 'm' instead of 'n' for the second array size
    for (int j = 0; j < m; j++) {
        cin >> arr2[j];
    }

    vector<int> intersection = FindIntersectionOfTwoArray(arr1, n, arr2, m);  // Fix: Pass 'm' as the second array size

    cout << "Intersection Of Two Arrays: ";
    for (int i = 0; i < intersection.size(); i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    return 0;
}
