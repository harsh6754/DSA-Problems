#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void isValidOrNot(int a, int b, int c){
        if(a+b>c || b+c>a || c+a>b){
            cout<<"Triangle is Valid";
        }else{
            cout<<"Not Valid";
        }
    }
};
int main(){
    int a,b,c;
    cin>>a>>b>>c;

    Solution solution;
    solution.isValidOrNot(a,b,c);

    return 0;
}