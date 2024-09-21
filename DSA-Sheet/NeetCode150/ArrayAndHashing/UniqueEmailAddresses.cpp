#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    void filterEmail(string& s, const string& email) {
        bool localName = true;
        for (int i = 0; i < email.size(); i++) {
            if (email[i] == '+' && localName) {
                while (email[i] != '@')
                    i++;
                localName = false;
            } else if (email[i] == '.' && localName) {
                continue; 
            } else if (email[i] == '@') {
                localName = false;
            } 

            s += email[i];
        }
    }
    public:
    int numUniqueEmails(vector<string>& emails){
        unordered_set<string>S;
        for(auto& email : emails){
            string s ="";
            filterEmail(s,email);
            if(S.find(s) == S.end()){
                S.insert(s);
            }
        }
        return S.size();
    }
};
int main(){
    int n;
    cin>>n;

    vector<string>emails(n);
    for(int i = 0;i<n;i++){
        cin>>emails[i];
    }

    Solution solution;
    int result = solution.numUniqueEmails(emails);
    cout<<result;
    return 0;
}