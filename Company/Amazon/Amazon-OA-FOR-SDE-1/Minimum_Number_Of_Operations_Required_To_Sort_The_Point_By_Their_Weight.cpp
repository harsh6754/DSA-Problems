#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int> &nums, vector<int> &dis) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        long long ans = 0;
        int nextAvail = nums.size();
        bool cont = true;

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].second > temp[i - 1].second && cont) continue;
            int k = ceil((nextAvail - temp[i].second) * 1.0 / dis[temp[i].second]);
            nextAvail = temp[i].second + k * dis[temp[i].second] + 1;
            cont = false;
            ans += k;
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the weight of point " << i + 1 << ": ";
        cin >> weight[i];
    }

    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the dist corresponding to the weight of point " << i + 1 << ": ";
        cin >> dist[i];
    }

    Solution solution;
    long long result = solution.minMoves(weight, dist);
    cout << "The minimum number of operations required to sort the points by their weight is: " << result << endl;

    return 0;
}
