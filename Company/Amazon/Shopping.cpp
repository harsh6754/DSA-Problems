#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int getMaximumRewardPoints(vector<int> reward) {
    sort(reward.begin(), reward.end(), greater<int>()); // Sort the rewards in descending order
    long int maxPoints = 0;
    int remainingPoints = 0;

    for (int i = 0; i < reward.size(); ++i) {
        if (reward[i] - i > 0) {
            maxPoints += reward[i] - i;
            remainingPoints += i; // Update the remaining points
        }
    }

    return maxPoints - remainingPoints;
}

int main() {
    int n;
    cin >> n;

    vector<int> reward(n);

    for (int i = 0; i < n; ++i) {
        cin >> reward[i];
    }

    long int result = getMaximumRewardPoints(reward);
    cout << result << endl;

    return 0;
}
