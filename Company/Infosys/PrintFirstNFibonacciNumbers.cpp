#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> printFibonacci(int n){
        vector<int>fibonacci;
        if(n <= 0){
            return fibonacci;
        }
        fibonacci.push_back(0);
        if(n == 1){
            return fibonacci;
        }
        fibonacci.push_back(1);
        for(int i = 2;i<n;i++){
            int next = fibonacci[i-1] + fibonacci[i-2];
            fibonacci.push_back(next);
        }
        return fibonacci;
    }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    vector<int>result = solution.printFibonacci(n);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return  0;
}