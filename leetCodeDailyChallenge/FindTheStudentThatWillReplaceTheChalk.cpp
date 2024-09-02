#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int chalkReplacer(vector<int>& chalk, int k){
        long long total = 0;
        for(int student : chalk){
            total+=student;
        }
        int rem = k % total;
        for(int i = 0;i<chalk.size();i++){
            if(rem < chalk[i]) return i;
            rem-=chalk[i];
        }
        return 0;
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
int main(){
    int n;
    cin>>n;

    vector<int>chalk(n);
    for(int i = 0;i<n;i++){
        cin>>chalk[i];
    }

    int k;
    cin>>k;

    Solution solution;
    int result = solution.chalkReplacer(chalk,k);
    cout<<result;

    return 0;
}