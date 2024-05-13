#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; ++i)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            int a = i + 1, b = nums.size() -1, t;
            while(a < b)
            {
                t = nums[i] + nums[a] + nums[b];
                if(t > 0)
                    b--;
                else if(t < 0)
                    a++;
                else
                {
                    ans.push_back({nums[i] , nums[a] , nums[b]});
                    a++; b--;
                    while(nums[a] == nums[a-1] && a < b)
                        a++;
                    while(nums[b] == nums[b+1] && a < b)
                        b--;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<vector<int>> result = sol.threeSum(nums);
    cout << "Triplets with sum 0 are:\n";
    for(auto triplet : result) {
        cout << "[";
        for(int i = 0; i < 3; ++i) {
            cout << triplet[i];
            if(i < 2) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
