//1281. Subtract the Product and Sum of Digits of an Integer 
//LeetCode
//Easy


#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int subtractProductAndSum(int n){
        int sum_of_digit = 0;
        int product_of_digit = 1;
        while(n > 0){
            int digit  = n%10;
            sum_of_digit+=digit;
            product_of_digit*=digit;
            n /= 10;
        }
        return product_of_digit - sum_of_digit;
    }
};

int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.subtractProductAndSum(n);
    cout<<result;

    return 0;
}