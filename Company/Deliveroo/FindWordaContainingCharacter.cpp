#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]==x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){
    int n;
    cin>>n;

    vector<string>words(n);
    for(int i = 0;i<n;i++)
    {
       cin>>words[i];
    }

    char x;
    cin>>x;

    Solution solution;
    vector<int>result=solution.findWordsContaining(words,x);
    
    for(auto x : result) cout<<x<<" ";

    return 0;
}