#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValid(vector<int>& arr){
        int n = arr.size();
        if (n == 0) return false;

        int i = 0;
        while (i < n) {
            if (arr[i] < 0 || arr[i] > 127) return false; // Check for valid UTF-8 byte range

            if ((arr[i] & 0x80) == 0) {
                // Single byte character
                i++;
            } else if ((arr[i] & 0xE0) == 0xC0) {
                // Two byte character
                if (i + 1 >= n || (arr[i + 1] & 0xC0) != 0x80) return false;
                i += 2;
            } else if ((arr[i] & 0xF0) == 0xE0) {
                // Three byte character
                if (i + 2 >= n || (arr[i + 1] & 0xC0) != 0x80 || (arr[i + 2] & 0xC0) != 0x80) return false;
                i += 3;
            } else if ((arr[i] & 0xF8) == 0xF0) {
                // Four byte character
                if (i + 3 >= n || (arr[i + 1] & 0xC0) != 0x80 || (arr[i + 2] & 0xC0) != 0x80 || (arr[i + 3] & 0xC0) != 0x80)
                    return false;
                i += 4;
            } else {
                return false; // Invalid UTF-8 start byte
            }
        }
        return true;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution solution;
    bool result = solution.isValid(arr);
    cout<< (result ? "true" : "false");
    
    return 0;
}