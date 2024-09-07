#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findNth(long long number){
        string result;
        while(number>0){
            result = to_string(number%9)+result;
            number = number/9;
        }
        return stol(result);
    }
};

int main(){
    long long number;
    cin>>number;

    Solution solution;
    long long result = solution.findNth(number);
    cout<<result;

    return 0;
}