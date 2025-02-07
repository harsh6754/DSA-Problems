#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
     vector<int> findPair(vector<int>& vec, int target){
       if (vec.size() == 0) return {};
       vector<int> result;
     
       unordered_map<int, int> map;
       int curMax = INT_MIN;
     
       for(int i = 0; i < vec.size(); i++){
         int toLook = target - 30 - vec[i];
       
         if( map.find(toLook) != map.end()){
           if( max(toLook, vec[i]) > curMax){
             curMax = max(toLook, vec[i]);
             result = {i, map[toLook]};
           }
         }
       
         map[vec[i]] = i;
       }
       return result;
     }
    };
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    int total;
    cin>>total;

    Solution solution;
    vector<int> result = solution.findPair(a, total);
    if (!result.empty()) {
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}