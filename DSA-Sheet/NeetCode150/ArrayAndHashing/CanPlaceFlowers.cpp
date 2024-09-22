#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            
            if (left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;        
    }
};
int main(){
    int M;
    cin>>M;

    vector<int>flowerbed(M);
    for(int i = 0;i<M;i++){
        cin>>flowerbed[i];
    }
    int n;
    cin>>n;

    Solution solution;
    bool result = solution.canPlaceFlowers(flowerbed,n);
    cout<<result ? 1 : 0;
    return 0;
}