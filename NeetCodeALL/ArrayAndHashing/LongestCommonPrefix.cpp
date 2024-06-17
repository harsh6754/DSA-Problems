#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0],last=strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;

    vector<string>strs(n);
    for(int i = 0;i<n;i++){
        cin>>strs[i];
    }

    Solution solution;
    string result = solution.longestCommonPrefix(strs);
    cout<<result;


    return 0;
}