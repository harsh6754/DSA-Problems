// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//      public:
//            void rotate(vector<int>&nums, int k){
//             int n = nums.size();
//             k = k % n;
//             reverse(nums.begin(),nums.end());
//             reverse(nums.begin(),nums.end() + k);
//             reverse(nums.begin() + k, nums.end());
//            }
// };

// int main(){
//     int n;
//     cin>>n;
//     vector<int>nums(n);
//     for(int i = 0;i<n;i++)
//     {
//         cin>>nums[i];
//     }

//     int k;
//     cin>>k;

//     Solution solution;
//     solution.rotate(nums,k);
//     for(int i = 0;i<n;i++)
//     {
//         cout<<nums[i]<<" ";
//     }

//     return 0;
// }

#include<bits/stdc++.h> // Include necessary libraries

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) { // Method to rotate the vector
        int n = nums.size();
        k = k % n; // To handle cases where k > n
        reverse(nums.begin(), nums.end()); // Reverse the entire vector
        reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the elements of the vector
    }

    int k;
    cin >> k; // Input the rotation count

    Solution solution;
    solution.rotate(nums, k); // Call the rotate method

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " "; // Output the rotated vector
    }

    return 0;
}
