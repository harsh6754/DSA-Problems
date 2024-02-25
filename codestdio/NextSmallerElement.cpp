#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (!s.empty() && s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements for each element: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
