#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < j; i++) {
            while (j >= 0 && numbers[i] + numbers[j] > target)
                j--;
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
        return {-1, -1};
    }
};

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(numbers, target);

    cout << "Result: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
