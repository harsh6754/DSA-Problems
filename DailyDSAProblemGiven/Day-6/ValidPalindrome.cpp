#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isPalindrome(string s) {

    transform(s.begin(),s.end(),s.begin(),::tolower);
    int i;
    for(i=0;i<s.size();i++){
         if(s[i]>=97&&s[i]<=122|| (s[i]>=48&&s[i]<=57)){
            continue;
        }
        else {
            s.erase(i,1);
            i--;
        }
    }
    int r=s.size()-1,l=0;
    while(l<r){
        if(s[l]!=s[r])
            return false ;
        l++;
        r--;
    }
    return true;
}
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    bool result = solution.isPalindrome(s);
    cout<<result ? 1 : 0;
    return 0;
}