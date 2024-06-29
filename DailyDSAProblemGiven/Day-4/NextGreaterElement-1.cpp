#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> next_greater;

    for (int num : nums2) {
        while (!s.empty() && s.top() < num) {
            next_greater[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    vector<int> result;
    for (int num : nums1) {
        if (next_greater.find(num) != next_greater.end()) {
            result.push_back(next_greater[num]);
        } else {
            result.push_back(-1);
        }
    }

    return result;
}

int main() {
    int n1, n2;
    cout << "Enter the number of elements in nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the number of elements in nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = nextGreaterElement(nums1, nums2);
    
    cout << "The next greater elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
