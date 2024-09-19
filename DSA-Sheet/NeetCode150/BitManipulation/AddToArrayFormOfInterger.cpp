#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    for (int i = num.size() - 1; i >= 0; --i) {
      num[i] += k;
      k = num[i] / 10;
      num[i] %= 10;
    }

    while (k > 0) {
      num.insert(num.begin(), k % 10);
      k /= 10;
    }

    return num;
  }
};

int main() {
    int n;
    cin >> n;

    vector<int> num(n); // Correct variable name
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int k;
    cin >> k;

    Solution solution;
    vector<int> result = solution.addToArrayForm(num, k); // Pass both num and k

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
