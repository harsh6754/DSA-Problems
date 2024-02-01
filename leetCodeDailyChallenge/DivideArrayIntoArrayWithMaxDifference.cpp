#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        if (size % 3 != 0)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result(size / 3, vector<int>(3));
        int groupIndex = 0;
        for (int i = 0; i < size; i += 3) {
            if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
                result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            }
            else {
                return vector<vector<int>>();
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int num;
    int k;

    cout << "Enter numbers (enter -1 to stop): ";
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }

    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> result = solution.divideArray(nums, k);

    if (result.size() == 0) {
        cout << "No valid groups found." << endl;
    } else {
        cout << "Valid groups:" << endl;
        for (const auto& group : result) {
            for (int num : group) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
