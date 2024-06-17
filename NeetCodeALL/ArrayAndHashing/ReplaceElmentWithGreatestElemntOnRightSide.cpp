#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> result(n, -1); 

//         if (n == 0) return result;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int maxRight = arr[i + 1];
//             for (int j = i + 2; j < n; j++)
//             {
//                 maxRight = max(maxRight, arr[j]);
//             }
//             result[i] = maxRight;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return arr;
        int maxRight = -1; 
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];
            arr[i] = maxRight; 
            maxRight = max(maxRight, current); 
        }
        
        return arr;
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
    vector<int>result = solution.replaceElements(arr);
    for(int i = 0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}