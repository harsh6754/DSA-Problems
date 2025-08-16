#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();
        vector<int> lastIndex(256,-1);
        int left = 0, maxLen = 0;

        for(int right = 0;right<n;right++){
            if(lastIndex[s[right]]>= left){
                left = lastIndex[s[right]]+=1;
            }
            lastIndex[s[right]] = right;
            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};

int main(){
    string s;
    getline(cin,s);

    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    cout<<result;

    return 0;
}