#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool ContainDuplicate(vector<int>& arr){
        int size = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<size;i++){
            mp[arr[i]]++;
        }
        for(auto i : mp){
            if(i.second == 2){
                return 1;
            }
        }
        return 0;
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
    bool result = solution.ContainDuplicate(arr);
    cout<<result ? 1:0;

    return 0;
}