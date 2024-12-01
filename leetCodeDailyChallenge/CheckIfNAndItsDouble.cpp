#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkIfExist(vector<int>& arr){
        unordered_map<int,int>mp;
        for(int i = 0;i<arr.size();i++){
            if(mp.find(arr[i]*2)!=mp.end() || (arr[i]%2==0 && mp.find(arr[i]/2)!=mp.end())){
                return true;
            }
            mp[arr[i]]++;
        }
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
    bool result = solution.checkIfExist(arr);
    if(!result){
        cout<<"False"<<endl;
    }else{
        cout<<"True"<<endl;
    }

    return 0;
}