#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxNumberOfBalloons(string text){
        int size = text.length();
        vector<int>v(26,0);
        for(int i = 0;i<size;i++){
            v[text[i]-'a']++;
        }
       int mini=v[1];
        mini=min(v[0],mini);
        mini=min(v[11]/2,mini);
        mini=min(mini,v[14]/2);
        mini=min(mini,v[13]);
        return mini;
    }
};
int main(){
    string text;
    getline(cin,text);

    Solution solution;
    int result = solution.maxNumberOfBalloons(text);
    cout<<result;

    return 0;
}