#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Include the numeric header for accumulate

using namespace std;

// Function to calculate the winner and the margin of victory
pair<string, int> calculateWinner(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: dp[i][i] represents the value of the single pile
    for (int i = 0; i < n; ++i) {
        dp[i][i] = piles[i];
    }

    // Build up the dp table using bottom-up dynamic programming
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
    }

    // Total cards collected by Dheeraj and Mansi
    int dheerajCards = (dp[0][n - 1] + accumulate(piles.begin(), piles.end(), 0)) / 2;
    int totalCards = accumulate(piles.begin(), piles.end(), 0);
    int mansiCards = totalCards - dheerajCards;

    // Determine the winner and the margin of victory
    string winner = (dheerajCards > mansiCards) ? "Dheeraj" : "Mansi";
    int margin = abs(dheerajCards - mansiCards);

    return make_pair(winner + " wins with " + to_string(margin) + " card" + (margin == 1 ? "!" : "s!"),margin);
}
int main() {
    // Input the initial distribution of card piles
    int n;
    cin >> n;
    vector<int> piles(n); // Create a vector of size n

    // Read the number of cards in each pile
    for(int i = 0; i < n; i++) {
        cin >> piles[i]; // Read the number of cards in the ith pile
    }

    // Calculate the winner and the margin of victory
    pair<string, int> result = calculateWinner(piles);

    // Output the result
    cout << result.first << endl;

    return 0;
}
