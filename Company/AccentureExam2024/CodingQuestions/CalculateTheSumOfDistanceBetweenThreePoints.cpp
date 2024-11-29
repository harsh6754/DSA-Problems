#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int calculateSumofDistance(int x1,int x2, int x3, int y1, int y2, int y3){
        int distance1 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        int distance2 = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        int distance3 = sqrt(pow(x3-x1,2)+pow(y3-y1,2));

        return distance1+distance2+distance3;
    }
};
int main(){
    int x1,y1;
    int x2,y2;
    int x3,y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;

    Solution solution;
    int result = solution.calculateSumofDistance(x1,y1,x2,y2,x3,y3);
    cout<<result;

    return 0;
}