#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int center (string s, int left, int right){
        int size = s.length();
        while(left >= 0 && right < size && s[left] == s[right]){
            left-=1;
            right+=1;
        }
        return right - left - 1;
    }

    string longestPalin(string s){
        int size = s.length();
        if(size<=1) return s;

        int start = 0;
        int maxLength = 1;

        for(auto& x : s){
            int length1 = center(s,x,x);
            int length2 = center(s,x,x+1);
            int length = max(length1,length2);

            if(length>maxLength){
                start = x - (length -1)/2;
                maxLength = length;
            }
        }
        return s.substr(start,maxLength);
    }

};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    string result = solution.longestPalin(s);
    for(auto& i : result){
        cout<<i<<" ";
    }
    return 0;
}