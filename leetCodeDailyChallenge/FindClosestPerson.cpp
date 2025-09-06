#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:2-(abs(x-z)<abs(y-z));
    }
};

int main(){
    int x,y,z;
    cin>>x>>y>>z;

    Solution solution;
    int result = solution.findClosest(x,y,z);
    cout<<result<<endl;

    return 0;
}