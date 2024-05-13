#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int topFreq = 0;
        for(int x: nums) {
            mp[x]++;
            topFreq = max(topFreq, mp[x]);
        }

        vector<int> ans;

        unordered_map<int, vector<int>> freqMap;
        for(auto it: mp) {
            freqMap[it.second].push_back(it.first);
        }

        int count=0;

        while(count<k) {
            if(freqMap.find(topFreq) != freqMap.end()) {
                vector<int> v = freqMap[topFreq];
                int n = v.size();
                for(int i=0; i<n; i++) {
                    ans.push_back(v[i]);
                    count++;
                    if(count == k)
                        break;
                }
            }
            topFreq--;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, k, num;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> result = sol.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements are:\n";
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
