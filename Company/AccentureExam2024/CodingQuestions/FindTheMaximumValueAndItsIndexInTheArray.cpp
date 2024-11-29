#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void MaxInArray(vector<int>&arr){
        int size = arr.size();
        int max = INT_MIN;
        int index = 0;
        for(int i = 0;i<size;i++){
            if(arr[i]>max){
                max = arr[i];
                index = i;
            }
        }
        cout<<max<<" "<<index<<endl;
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
    solution.MaxInArray(arr);

    return 0;
}