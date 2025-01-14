#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int KthSmallest(vector<int> &arr, int k) {
        return quickselect(arr, 0, arr.size() - 1, k);
    }

  private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    int quickselect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pi = partition(arr, low, high);

            if (pi == k - 1) {
                return arr[pi];
            } else if (pi > k - 1) {
                return quickselect(arr, low, pi - 1, k);
            } else {
                return quickselect(arr, pi + 1, high, k);
            }
        }
        return -1;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    Solution solution;
    int result = solution.KthSmallest(arr,k);
    cout<<result;

    return 0;
}