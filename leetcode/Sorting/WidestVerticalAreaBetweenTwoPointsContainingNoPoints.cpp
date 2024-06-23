#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x_coords;
        for (const auto& point : points) {
            x_coords.push_back(point[0]);
        }
        sort(x_coords.begin(), x_coords.end());
        
        int maxWidth = 0;
        for (size_t i = 1; i < x_coords.size(); ++i) {
            maxWidth = max(maxWidth, x_coords[i] - x_coords[i - 1]);
        }
        return maxWidth;
    }
};

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points as pairs of integers (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution solution;
    int result = solution.maxWidthOfVerticalArea(points);
    cout << "The widest vertical area is: " << result << endl;

    return 0;
}
