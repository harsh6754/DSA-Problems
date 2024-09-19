#include<bits/stdc++.h>
using namespace std;
// class Solution{
//     public:
//     string convertToTitle(int columnNumber){
//         string result ="";
//         while(columnNumber!=0){
//             int rem = columnNumber%26;
//             if(rem == 0) {
//                 result += "Z";
//                 columnNumber = (columnNumber/26) - 1;
//             }   
//             else {
//                 result += rem + 'A' -1;
//                 columnNumber = columnNumber/26;
//             }

//         }

//         //result.pop_back();
//         reverse(result.begin(),result.end());
//         return result;
//     }
// };

class Solution {
public:
       string convertToTitle(int columnNumber){
        string result ="";
        while(columnNumber>0){
            int rem = (columnNumber-1)%26;
            result += char(rem + 'A');
            
            columnNumber = (columnNumber-1)/26;
        }

        //result.pop_back();
        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){
    int columnNumber;
    cin>>columnNumber;

    Solution solution;
    string result = solution.convertToTitle(columnNumber);
    cout<<result;

    return 0;
}