#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ReverseArray(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans;

        // Traverse the array in reverse order
        for (int i = size - 1; i >= 0; i--) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input size." << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    vector<int> result = solution.ReverseArray(arr);

    // Print the reversed array
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
