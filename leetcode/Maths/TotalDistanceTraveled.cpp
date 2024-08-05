#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
       int res=0;
        while(mainTank>=5){
            res+=5*10;
            mainTank-=5;
            if(additionalTank>=1) {
                mainTank+=1;
                additionalTank--;
            }
        }
       res+=(mainTank*10);
        return res;
    }
};
int main(){
    int mainTank;
    cin>>mainTank;

    int additionalTank;
    cin>>additionalTank;

    Solution solution;
    int result = solution.distanceTraveled(mainTank,additionalTank);
    cout<<result;

    return 0;
}