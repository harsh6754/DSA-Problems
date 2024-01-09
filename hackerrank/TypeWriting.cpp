#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string str, opStr;
    int n;
    cin>>str>>opStr;
    cin>>n;
    
    int m = opStr.size();
    bool flag = 0;
    int undu = 0;
    for(int i = 0; i < m; i++) {
        char op = opStr[i];
        
        if(op == 'w') {
            undu = 0;
            flag = 1;
            continue;
        }
        
        if(op == 'd') {
            
            flag = 0;
            
            // delet n size
            int val = n;
            while(val--) {
                str.pop_back();
                undu--;
            }
            
        }    
            
        if(op == 'u') {
            flag = 0;
            while(undu--) {
                str.pop_back();
            }

        } 
        if(flag) {
            str.push_back(op);
            undu++;
        }    

    }
    
    cout<<str;
    
    return 0;
}