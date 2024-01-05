#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(std::vector<int>& arr)
    {
        int n = arr.size();
        int ans = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                ans = arr[i];
                break;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    Solution solution;
    int duplicate = solution.findDuplicate(arr);

    cout << "Duplicate Element: " << duplicate << endl;

    return 0;
}
