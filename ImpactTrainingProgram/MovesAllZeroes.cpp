#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
           int movesZeroes(vector<int>&arr)
           {
            int n = arr.size();
            for(int i = 0;i<n;i++)
             {
                for(int j = 0;j<n;j++){
                    if(arr[j+1] == 0)
                    {
                        swap(arr[j],arr[j+1]);
                    }
                }
             }
           }
}

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    Solution solution;
    int result = solution.movesZeroes(arr);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i];
    }

    return 0;
}