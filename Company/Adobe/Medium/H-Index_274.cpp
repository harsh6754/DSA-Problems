#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int hIndex(vector<int>& citations){
        sort(citations.begin(),citations.end(),greater<int>());
        int h = 0;
        for(int i = 0;i<citations.size();i++){
            if(citations[i]>= i+1){
                h=i+1;
            }else{
                break;
            }
        }
        return h;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>citations(n);
    for(int i = 0;i<n;i++){
        cin>>citations[i];
    }

    Solution solution;
    int result = solution.hIndex(citations);
    cout<<result;

    return 0;
}