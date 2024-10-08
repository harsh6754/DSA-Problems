#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minSwaps(string s){
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};
int main(){
    string s;
    getline(cin,s);

    Solution solution;
    int result = solution.minSwaps(s);
    cout<<result;

    return 0;
}