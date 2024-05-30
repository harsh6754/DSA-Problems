#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum order volume
int maximizeOrderVolume(vector<int>& start, vector<int>& duration, vector<int>& volume) {
    int n = start.size();
    vector<tuple<int, int, int>> calls(n);

    // Create a vector of tuples (end_time, start_time, volume)
    for (int i = 0; i < n; ++i) {
        calls[i] = make_tuple(start[i] + duration[i], start[i], volume[i]);
    }

    // Sort the calls by their end time
    sort(calls.begin(), calls.end());

    // DP array to store the maximum volume up to each call
    vector<int> dp(n, 0);
    dp[0] = get<2>(calls[0]);

    for (int i = 1; i < n; ++i) {
        int incl = get<2>(calls[i]);
        int l = -1;

        // Find the latest non-overlapping call
        for (int j = i - 1; j >= 0; --j) {
            if (get<0>(calls[j]) <= get<1>(calls[i])) {
                l = j;
                break;
            }
        }

        if (l != -1) {
            incl += dp[l];
        }

        dp[i] = max(incl, dp[i - 1]);
    }

    // The last element of dp will have the maximum volume
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), duration(n), volume(n);
    for (int i = 0; i < n; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> duration[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> volume[i];
    }

    cout << maximizeOrderVolume(start, duration, volume) << endl;

    return 0;
}
