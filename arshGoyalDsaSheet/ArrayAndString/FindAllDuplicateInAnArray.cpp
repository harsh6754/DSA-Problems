#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> v;

        for(int i=0; i<nums.size(); i++) {
            if(st.count(nums[i])) {
                // If element is present
                v.push_back(nums[i]);
            } else {
                // If element is not present
                st.insert(nums[i]);
            }
        }
        return v;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> duplicates = solution.findDuplicates(nums);

    cout << "Duplicates in the array are: ";
    for(int i=0; i<duplicates.size(); i++) {
        cout << duplicates[i] << " ";
    }
    
    return 0;
}
