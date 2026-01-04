#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string reverseString(string str){
        int left = 0;
        int right = str.length() - 1;
        while(left < right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
        return str;
    }
};
int main(){
    string str;
    getline(cin,str);

    Solution solution;
    string result = solution.reverseString(str);
    cout<<result<<endl; 

    return 0;
}