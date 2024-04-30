#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void findUniquePartitions(int ind, int sum, vector<int>& num, vector<int>& ds, vector<vector<int>>& v, int n){
        if(sum >= n || ind >= n){
            if(sum == n) v.push_back(ds);
            return;
        }
        ds.push_back(num[ind]);
        findUniquePartitions(ind, sum + num[ind], num, ds, v, n);
        ds.pop_back();
        findUniquePartitions(ind + 1, sum, num, ds, v, n);
    }

    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> v;
        vector<int> ds, num;
        for(int i = n; i >= 1; i--) num.push_back(i);
        findUniquePartitions(0, 0, num, ds, v, n);
        return v;
    }
};

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution solution;
    vector<vector<int>> result = solution.UniquePartitions(n);

    cout << "Unique Partitions of " << n << " are:\n";
    for(auto partitions : result){
        for(int num : partitions){
            cout << num << " ";
        }
        cout << " ";
    }

    return 0;
}
