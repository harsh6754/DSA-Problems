#include <iostream>
#include <vector>

using namespace std;

int findMajority(vector<int>& nums, int n) {
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }
    if (maxCount > n / 2)
        return nums[index];
    else
        return -1; // No majority element found
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int majorityElement = findMajority(nums, n);

    if (majorityElement != -1) {
        cout << "Majority Element: " << majorityElement << endl;
    } else {
        cout << "No Majority Element" << endl;
    }

    return 0;
}
