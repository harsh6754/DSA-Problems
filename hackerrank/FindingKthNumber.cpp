#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool division(int i, vector<int> div) {
    for(auto x : div) {
        if(i % x == 0) {
            return 1;
        }
    }
    return 0;
}

int findKthValue(int n, vector<int> div,int k) {
    if(k < 2) return -1;
    
    int i = 1;
    while(k) {
        i++;
        if(division(i, div)){
            k--;
        }
        
    }
    
    return i;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin>>n;
    vector<int> div(n);
    for(int i = 0; i<n; i++) {
        cin>>div[i];
    }
    
    int k;
    cin>>k;
    
    int ans = findKthValue(n, div, k);
    
    cout<<ans;
    
    return 0;
}