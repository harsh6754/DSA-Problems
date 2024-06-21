#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerReplacement(int N) 
    {
        long long n = N, cnt = 0;
        while(n != 1)
        {
            cnt++;
            if(n%2) 
            {
                if(n==3) 
                {
                    n--;
                    continue;
                }
                if(((n-1)/2)%2==0 and ((n+1)/2)%2==0) n--;
                else if(((n+1)/2)%2==0) n++;
                else n--;
            }
            else n /= 2;
        }
        return cnt;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.integerReplacement(n);
    cout<<result;
    

    return 0;
}