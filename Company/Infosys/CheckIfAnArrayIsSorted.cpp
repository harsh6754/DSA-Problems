#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isSorted(vector<int>&arr){
        int i = 0;
        while(i < arr.size() - 1)
        {
            if (arr[i] > arr[i+1])
            {
                return false;
            }
            i++;
        }
        return true; 
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    bool isSorted = solution.isSorted(arr);
    cout<< (isSorted ? "Array is sorted" : "Array is not sorted") << endl;

    return 0;
}