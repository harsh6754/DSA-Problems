#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for(auto interval : intervals){
        if(merged.empty() || merged.back()[1] < interval[0]){
            merged.push_back(interval);
        }else{
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    for(auto interval : merged){
        cout<<interval[0]<<" "<<interval[1]<<endl;
    }
    return 0;
}