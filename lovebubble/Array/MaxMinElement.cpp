#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
#include <vector>

using namespace std;

int getMax(const vector<int>& nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
        {
            maxi = nums[i];
        }
    }
    return maxi;
}

int getMin(const vector<int>& nums)
{
    int minVal = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minVal)
        {
            minVal = nums[i];
        }
    }
    return minVal;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    cout << "Max Value in Array --> " << getMax(nums) << endl;
    cout << "Min Value in Array --> " << getMin(nums) << endl;

    return 0;
}
