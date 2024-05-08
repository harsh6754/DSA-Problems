#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
          vector<int>countBits(int n){
            vector<int>ans(n + 1);
            for(int i = 0;i<=n;i++){
                int num = i;
                int cnt = 0;
                while(num > 0){
                    if(num & 1){
                        cnt+=1;
                    }
                    num = num >>1;
                }
                ans[i] = cnt;
            }
            return ans;
          }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    vector<int> result = solution.countBits(n);
    for(int i = 0;i<n;i++){
        cout<<result[i];
    }

    return 0;
}