#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int vowelStrings(vector<string>&words, int Left, int Right){
    int count = 0;
    string vowel = "aeiou";
    for(int i = Left;i<=Right;i++){
        char start = words[i][0], end = words[i][words[i].length()-1];
        if((vowel.find(start)!= string::npos) && (vowel.find(end) !=  string::npos)){
            count++;
        }
    }
    return count;
    }
};
int main(){
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i = 0;i<n;i++){
        cin>>words[i];
    }

    int Left;
    int Right;
    cin>>Left>>Right;

    Solution solution;
    int result = solution.vowelStrings(words,Left,Right);
    cout<<result;
    return 0;
}