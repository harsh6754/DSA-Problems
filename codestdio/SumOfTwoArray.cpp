#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v) {
    int s = 0;
    int e = v.size() - 1;

    while (s < e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0) {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    while (j >= 0) {
        int sum = b[j] + carry;
        carry = sum / 10;
        int value = sum % 10;
        ans.push_back(value);
        j--;
    }

    while (carry != 0) {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

int main() {
    // Taking input from the user
    cout << "Enter the number of digits in the first number: ";
    int n;
    cin >> n;

    vector<int> a(n);
    cout << "Enter the digits of the first number (from the least significant digit to the most significant digit): ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Enter the number of digits in the second number: ";
    int m;
    cin >> m;

    vector<int> b(m);
    cout << "Enter the digits of the second number (from the least significant digit to the most significant digit): ";
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> result = findArraySum(a, n, b, m);

    // Print the result
    cout << "Sum: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
