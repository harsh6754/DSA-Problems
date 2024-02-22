#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string smallestWindow(string S, string P)
    {
        vector<int> a(26, 0);
        int cnt=0, i=0, j=0, n=S.size(), l=-1, r=-1;

        for(char x: P){
            a[x-'a']++;
            if(a[x-'a']==1) cnt++;
        }

        while(j<n){
            a[S[j]-'a']--;
            if(a[S[j]-'a']==0) cnt--;

            while(cnt==0){
                if( (l==-1 && r==-1) || ((r-l)>(j-i)) ){
                    l=i;
                    r=j;
                }

                a[S[i]-'a']++;
                if(a[S[i]-'a']==1) cnt++;
                i++;
            }

            j++;
        }

        if(l==-1 && r==-1) return "-1";

        string ans="";

        for(int k=l; k<=r; k++) ans+=S[k];

        return ans;
    }
};

int main()
{
    string S;
    string P;

    cin>>S;
    cin>>P;

    Solution solution;
    string result = solution.smallestWindow(S,P);
    cout<<result;

    return 0;
}

