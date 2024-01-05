#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int j = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]){
                arr[j] = arr[i];
                j++;
            }
        }
        return j;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution solution;
    int duplicate = solution.removeDuplicates(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout<<endl;
    cout << duplicate << endl;
    return 0;
}