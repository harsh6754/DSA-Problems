#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSubArray(vector<int>& num){
        int sum = INT_MIN;
        int currentSum = 0;

        for(int i = 0;i<num.size();i++){
          currentSum = max(num[i],currentSum+num[i]);
          sum = max(sum,currentSum); 
        }
        return sum;
    }

};

int main(){
    int n;
    cin>>n;

    vector<int>num(n);
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }

    Solution solution;
    int result = solution.maxSubArray(num);
    cout << result << " ";

    return 0;
}