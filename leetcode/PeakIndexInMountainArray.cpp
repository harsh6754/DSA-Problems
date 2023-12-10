#include <vector>
#include <iostream>
class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

 

int main() {
    Solution solution;
    std::vector<int> mountainArray = {1, 3, 20, 4, 1, 0};

    int peakIndex = solution.peakIndexInMountainArray(mountainArray);

    std::cout << "Peak index in the mountain array: " << peakIndex << std::endl;

    return 0;
}
