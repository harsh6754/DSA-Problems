#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string solutions(string a,string b){
    int n=a.length();
    int m=b.length();
    if(n<m){
        return solutions(b,a);
    }
    string ans="";
    for(int i=0;i<n-m;i++){
        ans+=a[i];
    }
    for(int i=n-m;i<n;i++){
        ans+=to_string((a[i]-'0')+(b[i-n+m]-'0'));
    }
    return ans;
    }
};

int main(){
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);

    Solution solution;
    string result = solution.solutions(a,b);
    cout<<result;

    return 0;
}