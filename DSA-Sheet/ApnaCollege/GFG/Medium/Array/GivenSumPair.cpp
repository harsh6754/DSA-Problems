#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool pairInSortedRotated(vector<int>& arr, int target){
        int size = arr.size();
        int i;      
        for(i = 0;i<size-1;i++){
            if(arr[i]>arr[i+1]){
                break;
            }
        }   
        int low = (i+1)%size;
        int high = i;
        while(low!=high){
            if(arr[low]+arr[high] == target){
                return true;
            }
            if(arr[low]+arr[high]<target){
                low = (low+1)%size;
            }else{
                high = (size+high-1)%size;
            }
        }
        return false;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    Solution solution;
    bool result = solution.pairInSortedRotated(arr,target);
    cout<<result ? 1 : 0;

    return 0;
}