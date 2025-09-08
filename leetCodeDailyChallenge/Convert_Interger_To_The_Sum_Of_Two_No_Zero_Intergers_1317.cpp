#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> getNoZeroIntergers(int n){
        for(int i = 1; i < n; i++){
            int a = i;
            int b = n - i;
            string strA = to_string(a);
            string strB = to_string(b);
            if(strA.find('0') == string::npos && strB.find('0') == string::npos){
                return {a, b};
            }
        }
        return {};
    }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    vector<int>result = solution.getNoZeroIntergers(n);
    for(int num : result){
        cout<<num<<" ";
    }

    return 0;
}