#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void subsetsHelper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result)
    {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            subsetsHelper(nums, i + 1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        subsetsHelper(nums, 0, current, result);
        return result;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    // Printing the subsets in the required format
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
