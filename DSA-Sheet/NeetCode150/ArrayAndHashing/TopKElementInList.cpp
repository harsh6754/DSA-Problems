#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> mp;
        
        // Counting frequency of each number
        for (int i = 0; i < size; i++) {
            mp[nums[i]]++;
        }
        
        // Min-heap to store the top K frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Push frequencies to the heap
        for (auto& i : mp) {
            minHeap.push({i.second, i.first});
            if (minHeap.size() > k) {
                minHeap.pop();  // Keep only the top k elements
            }
        }
        
        vector<int> ans;
        // Extracting elements from the heap
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int k;
    cin >> k;

    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    
    for (auto& num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
