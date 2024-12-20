#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxChunksToSorted(vector<int>& arr){
        int size = arr.size();
        int chunkCount  = 0;
        int maxElement = 0;
        for(int i = 0;i<size;i++){
            maxElement = max(maxElement,arr[i]);
            if(maxElement == i){
            chunkCount+=1;
            }
        }
        return chunkCount;
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
    int result = solution.maxChunksToSorted(arr);
    cout<<result;

    return 0;
}