#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string findFirstNonRepeatingCharAndReplaceWithHash(string s){
        unordered_map<char,int> charCount;
        queue<char> charQueue;
        string result;
        for(char ch : s){
            charCount[ch]++;
            if(charCount[ch] == 1){
                charQueue.push(ch);
            }
            while(!charQueue.empty() && charCount[charQueue.front()] > 1){
                charQueue.pop();
            }
            if(!charQueue.empty()){
                result += charQueue.front();
            } else {
                result += '#';
            }
        }   
        return result;
    }
};

int main(){
    string s;
    getline(cin,s);
    Solution solution;
    string result = solution.findFirstNonRepeatingCharAndReplaceWithHash(s);
    cout<<result<<endl;

    return 0;
}