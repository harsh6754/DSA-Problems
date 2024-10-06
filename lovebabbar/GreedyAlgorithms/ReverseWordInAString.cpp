#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string reverseWords(string S){
    vector<string> words;
    stringstream ss(S);
    string word;
    
    while (getline(ss, word, '.')) {
        if (!word.empty()) {
            
            // Ignore empty words caused by multiple dots
            words.push_back(word);
        }
    }
    
    // Reverse the words
    reverse(words.begin(), words.end());
    
    // Join the reversed words back into a string
    string result;
    for (int i = 0; i < words.size(); ++i) {
        if (i > 0) {
            result += '.';
        }
        result += words[i];
    }
    
    return result;
    }
};
int main(){
    string S;
    getline(cin,S);

    Solution solution;
    string result = solution.reverseWords(S);
    cout<<result;

    return 0;
}