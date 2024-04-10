#include<bits/stdc++.h>
using namespace std;

vector<int> FindIntersectionOfTwoArray(vector<int> nums1, int n, vector<int> nums2)
{
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int element = nums1[i];

        for(int j = 0; j < n; j++)
        {
            if(element == nums2[j])
            {
                ans.push_back(element);
                nums2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Size of Array: ";
    cin >> n;

    vector<int> nums1(n);
    vector<int> nums2(n);

    cout << "Enter elements of first array:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter elements of second array:" << endl;
    for(int j = 0; j < n; j++)
    {
        cin >> nums2[j];
    }

    vector<int> intersection = FindIntersectionOfTwoArray(nums1, n, nums2);

    cout << "Intersection Of Two Arrays: ";
    for (int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << " ";
    }
    cout << endl;

    return 0;
}
