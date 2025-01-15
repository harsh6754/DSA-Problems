#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string findLargest(vector<int>& arr){
        vector<string>str;
        for(auto x:arr){
            str.push_back(to_string(x));
        }
        sort(str.begin(),str.end(),[](string &a,string &b){
            return a+b>b+a;
        });
        string result = "";
        for(auto x:str){
            result += x;
        }
        return result;
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
    string result = solution.findLargest(arr);
    cout<<result;

    return 0;
}