#include <iostream>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int ith_bit = (num >> i-1) & 1;
        
        int set_bit = (num | (1 << i-1));
        
        int clear_bit = (num & ~(1 << i-1));
        
        cout << ith_bit << " " << set_bit << " " << clear_bit;
        
    }
};
int main() {
    Solution sol;
    int num, i;
    cin >> num >> i; // Input the number and the bit position
    sol.bitManipulation(num, i);
    return 0;
}
