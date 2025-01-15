#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longSubarrDivByK(vector<int>& arr, int k){
        unordered_map<int,int>mp;
        int sum = 0;
        int max_length = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            int rem = ((sum % k) + k) % k;
            if(rem == 0){
                max_length = i+1;
            }
            else if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            }
            else{
                max_length = max(max_length,i-mp[rem]);
            }
        }
        return max_length;
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
    int result = solution.longSubarrDivByK(arr,k);
    cout<<result;

    return 0;
}