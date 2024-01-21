
// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size(); 
//         if (n < 2) return n ? nums[0] : 0;
//         return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
//     }

// private:
//     int robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         for (int i = l; i <= r; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };

// int main() {
//     Solution solution;
//     int size;
//     cin >> size;

//     vector<int> nums(size);
//     for (int i = 0; i < size; ++i) {
//         cin >> nums[i];
//     }
//     int result = solution.rob(nums);
//     cout << result << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     pair<int, pair<int, int>> rob(vector<int>& nums) {
//         int n = nums.size(); 
//         if (n < 2) return {n ? nums[0] : 0, {n ? 0 : -1, -1}};

//         pair<int, pair<int, int>> result1 = robber(nums, 0, n - 2);
//         pair<int, pair<int, int>> result2 = robber(nums, 1, n - 1);

//         if (result1.first > result2.first) {
//             return result1;
//         } else {
//             result2.second.first += 1; // Increment index for the second subset
//             result2.second.second += 1; // Increment index for the second subset
//             return result2;
//         }
//     }

// private:
//     pair<int, pair<int, int>> robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         pair<int, int> indices = {-1, -1};
//         for (int i = l; i <= r; i++) {
//             if (pre + nums[i] > cur) {
//                 indices.first = indices.second;
//                 indices.second = i;
//                 int temp = pre + nums[i];
//                 pre = cur;
//                 cur = temp;
//             } else {
//                 pre = cur;
//             }
//         }
//         return {cur, indices};
//     }
// };

// int main() {
//     Solution solution;
//     int size;
//     cin >> size;

//     vector<int> nums(size);
//     for (int i = 0; i < size; ++i) {
//         cin >> nums[i];
//     }

//     pair<int, pair<int, int>> result = solution.rob(nums);

//     cout << "Maximum amount that can be robbed: " << result.first << endl;
//     cout << "Indices of selected elements: [" << result.second.first + 1 << ", " << result.second.second + 1 << "]" << endl;

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    pair<int, pair<int, int>> rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return {n ? nums[0] : 0, {n ? 0 : -1, -1}};

        pair<int, pair<int, int>> result1 = robber(nums, 0, n - 2);
        pair<int, pair<int, int>> result2 = robber(nums, 1, n - 1);

        if (result1.first > result2.first) {
            return result1;
        } else {
            result2.second.first += 1; // Increment index for the second subset
            result2.second.second += 1; // Increment index for the second subset
            return result2;
        }
    }

private:
    pair<int, pair<int, int>> robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        pair<int, int> indices = {-1, -1};
        for (int i = l; i <= r; i++) {
            if (pre + nums[i] > cur) {
                indices.first = indices.second;
                indices.second = i;
                int temp = pre + nums[i];
                pre = cur;
                cur = temp;
            } else {
                pre = cur;
            }
        }
        return {cur, indices};
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);

    cout << "Enter space-separated elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    Solution solution;
    pair<int, pair<int, int>> result = solution.rob(nums);

    cout << result.first << endl;
    cout << result.second.first + 1 << " " << result.second.second + 1<< endl;

    return 0;
}



// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) return n ? nums[0] : 0;
//         return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
//     }

// private:
//     int robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         for (int i = l; i <= r; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };

// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;

//     vector<int> nums(size);

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < size; i++) {
//         cin >> nums[i];
//     }

//     Solution solution;
//     int result = solution.rob(nums);

//     cout << "Maximum amount that can be robbed: " << result << endl;

//     return 0;
// }

