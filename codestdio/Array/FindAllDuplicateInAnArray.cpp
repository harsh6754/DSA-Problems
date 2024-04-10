#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicate(vector<int>& nums, int n) {
    vector<int> result;
    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        frequency[nums[i]]++;
    }

    for (auto it : frequency) {
        if (it.second > 1) {
            result.push_back(it.first);
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter Array Size: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> duplicates = findDuplicate(arr, n);

    if (duplicates.empty()) {
        cout << "No duplicates found." << endl;
    } else {
        cout << "All Duplicate Elements in Array: ";
        for (int i = 0; i < duplicates.size(); i++) {
            cout << duplicates[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
