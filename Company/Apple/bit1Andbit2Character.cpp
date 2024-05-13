#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isOneBitCharacter(vector<int>&bits){
        int n = bits.size();
        int i = 0;
        while(i<n - 1){
            if(bits[i] == 0){
                i+=1;
            }else{
                i+=2;
            }
        }
        return i == n-1;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>bits(n);
    for(int i = 0;i<n;i++){
        cin>>bits[i];
    }

    Solution solution;
    bool result = solution.isOneBitCharacter(bits);
    cout<<result;
    if(result){
        return 1;
    }else{
        return 0;
    }


    return 0;
}