#include <bits/stdc++.h>
using namespace std;

bool findUniqueNumberOfOccurence(int arr[], int size) {
    unordered_map<int, int> freq;
    unordered_set<int> st;   
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }
    for (auto it : freq) {
        auto temp = st.emplace(it.second);
        if (!temp.second) {
            cout << "Frequency " << it.second << " is not unique." << endl;
            return false;
        }
    }
    cout << "All frequencies are unique." << endl;
    return true;
}

int main() {
    int size;
    cout << "Enter the array size: ";
    cin >> size;

    int arr[100];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bool allFrequenciesUnique = findUniqueNumberOfOccurence(arr, size);
    if (allFrequenciesUnique) {
        cout << "All frequencies in the array are unique." << endl;
    } else {
        cout << "Not all frequencies in the array are unique." << endl;
    }

    return 0;
}
