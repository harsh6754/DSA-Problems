#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> seen;
        int dup = -1, missing = -1;

        for (int num : nums) {
            if (seen.count(num) == 0) {
                seen.insert(num);
            } else {
                dup = num;
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (seen.count(i) == 0) {
                missing = i;
                break;
            }
        }

        return {dup, missing};
    }
};

int main() {
    // Get input from the user
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums;
    cout << "Enter " << n << " elements of the array separated by spaces: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Create a Solution object
    Solution solution;

    // Find duplicate and missing numbers
    vector<int> result = solution.findErrorNums(nums);

    // Display the result
    cout << "Duplicate number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
