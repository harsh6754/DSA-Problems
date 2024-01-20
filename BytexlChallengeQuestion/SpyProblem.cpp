#include <iostream>
#include <vector>

using namespace std;

int maxStolenMoney(vector<int>& houses, vector<int>& chosenHouses) {
    int n = houses.size();
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        chosenHouses.push_back(0);  // 0-based index
        return houses[0];
    }

    // Dynamic programming approach
    vector<int> dp(n, 0);
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]);
    }

    int maxMoney = dp[n - 1];

    // Backtracking to find the positions of the houses chosen for attack
    int i = n - 1;
    while (i >= 2) {
        if (dp[i] == dp[i - 1]) {
            i -= 1;
        } else {
            chosenHouses.push_back(i); // 0-based index
            i -= 2;
        }
    }
    if (i == 1) {
        chosenHouses.push_back(0);
    }

    return maxMoney;
}

int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> houses(n);
    cout << "Enter the money in each house (space-separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> houses[i];
    }

    vector<int> chosenHouses;
    int maxMoney = maxStolenMoney(houses, chosenHouses);

    cout << "Maximum stolen money: " << maxMoney << endl;

    // Printing the house positions
    cout << "Chosen house positions (0-based index): ";
    for (int i = chosenHouses.size() - 1; i >= 0; --i) {
        cout << chosenHouses[i] + 1 << " ";  // 1-based index
    }
    cout << endl;

    return 0;
}
