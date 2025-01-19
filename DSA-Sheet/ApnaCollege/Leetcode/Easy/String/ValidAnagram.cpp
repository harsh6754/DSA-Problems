#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()){
            return false;
        }
        int n = s.length();
        int count[256] = {0};
        for(int i = 0; i < n; i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(int i = 0; i < 256; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
};
int main(){
    string s;
    string t;

    getline(cin,s);
    getline(cin,t);

    Solution solution;
    bool result = solution.isAnagram(s,t);
    cout<<result ? 1 : 0;

    return 0;
}