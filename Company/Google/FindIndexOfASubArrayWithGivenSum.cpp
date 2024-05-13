#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int n, long long s) {
        int i = 0;
        int j = 0;
        if (s == 0) return {-1};
        vector<int> ans;
        long long sum = 0;
        while (j < n) {
            sum += arr[j];
            if (sum > s) {
                while (sum > s && i < j) {
                    sum -= arr[i];
                    i++;
                }
            }
            if (sum == s) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            j++;
        }
        return {-1}; // If no subarray with the given sum is found
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long sum;
    cout << "Enter the sum: ";
    cin >> sum;

    Solution solution;
    vector<int> result = solution.subarraySum(nums, n, sum);

    if (result[0] == -1) {
        cout << "No subarray with the sum " << sum << " found.\n";
    } else {
        cout << "Subarray with the sum " << sum << " found at indices: ";
        for (int i = result[0]; i <= result[1]; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
