#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    static bool compare(int a, int b){
        string str1 = to_string(a) + to_string(b);
        string str2 = to_string(b) + to_string(a);
        return str1 > str2;
    }
    string largeNumber(vector<int>&arr, int N){
        sort(arr.begin(), arr.end(), compare);
        string result = "";
        for(int i = 0;i<N;i++){
            result += to_string(arr[i]);
        }
        // Handle the case where all numbers are zero
        if(result[0] == '0'){
            return "0";
        }
        return result;
    }
};

int main(){
    int N;
    cin>>N;

    vector<int>arr(N);
    for(int i = 0;i<N;i++){
        cin>>arr[i];
    }

    Solution solution;
    string largestNumber = solution.largeNumber(arr,N);
    cout<<largestNumber<<endl;

    return 0;
}  