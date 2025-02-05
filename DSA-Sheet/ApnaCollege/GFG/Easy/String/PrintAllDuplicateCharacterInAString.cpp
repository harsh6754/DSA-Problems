#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void printDuplicate(string s){
        unordered_map<char,int>mp;
        for(int i = 0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto x : mp){
            if(x.second>1){
                cout<<x.first<<", count = "<<x.second<<endl;
            }
        }
    }
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    solution.printDuplicate(s);

    return 0;
}