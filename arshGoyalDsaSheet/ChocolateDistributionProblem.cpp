#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
    sort(a.begin(),a.end());
    int i = 0;
    int j = m-1;
    
    int mini = INT_MAX;
    while(j< a.size()){
        int diff = a[j] - a[i];
        mini = min(mini,diff);
        i++;
        j++;
        
    }
    return mini;
    }   
};

int main() {
    Solution solution;

    long long n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<long long> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long m;
    cout << "Enter the value of m: ";
    cin >> m;

    long long result = solution.findMinDiff(arr, n, m);  // Change result to long long

    if (result != -1) {
        cout << "Minimum difference after considering subarrays of size " << m << ": " << result << endl;
    } else {
        cout << "Invalid input for m or n." << endl;
    }

    return 0;
}
